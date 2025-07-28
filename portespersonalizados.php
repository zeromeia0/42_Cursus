<?php
if (!defined('_PS_VERSION_')) {
    exit;
}

class PortesPersonalizados extends Module
{
    public function __construct()
    {
        $this->name = 'portespersonalizados';
        $this->tab = 'shipping_logistics';
        $this->version = '4.0.0';
        $this->author = 'Vinicius Vaz';
        $this->need_instance = 0;
        $this->bootstrap = true;
        $this->ps_versions_compliancy = ['min' => '1.7', 'max' => _PS_VERSION_];

        parent::__construct();

        $this->displayName = $this->l('Custom Shipping by Region');
        $this->description = $this->l('Filters carriers and calculates shipping by postal code regions');
    }

    public function install()
    {
        return parent::install() &&
            $this->registerHook('filterCarrierList') &&
            $this->registerHook('displayBeforeCarrier') &&
            $this->registerHook('actionCarrierProcess') &&
            $this->installDatabase();
    }

    public function uninstall()
    {
        return parent::uninstall() &&
            $this->uninstallDatabase();
    }

    private function installDatabase()
    {
        return Db::getInstance()->execute('
            CREATE TABLE IF NOT EXISTS `'._DB_PREFIX_.'portes_regions` (
                `id` INT UNSIGNED NOT NULL AUTO_INCREMENT,
                `postcode_prefix` VARCHAR(5) NOT NULL,
                `region` VARCHAR(50) NOT NULL,
                PRIMARY KEY (`id`),
                INDEX (`postcode_prefix`)
            ) ENGINE='._MYSQL_ENGINE_.' DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
        ');
    }

    private function uninstallDatabase()
    {
        return Db::getInstance()->execute('DROP TABLE IF EXISTS `'._DB_PREFIX_.'portes_regions`');
    }

    // CORE FUNCTIONALITY

public function hookFilterCarrierList($carriers)
{
    if (!$this->context->cart->id_address_delivery) {
        error_log("PortesPersonalizados: No delivery address, returning all carriers.");
        return $carriers;
    }

    $address = new Address($this->context->cart->id_address_delivery);
    $region = $this->getRegionFromPostcode($address->postcode);
    
    error_log("PortesPersonalizados: Customer postcode {$address->postcode}, Region: $region");

    $allowedCarriers = $this->getCarriersForRegion($region);
    error_log("PortesPersonalizados: Allowed carriers for region $region: " . json_encode($allowedCarriers));

    // If no allowed carriers found, either block shipment or return empty
    if (empty($allowedCarriers)) {
        error_log("PortesPersonalizados: No carriers allowed for region $region, returning empty list");
        return [];
    }

    // Filter the carriers list to only allowed carriers
    $filtered = array_filter($carriers, function($carrier) use ($allowedCarriers) {
        return in_array($carrier['id_carrier'], $allowedCarriers);
    });

    error_log("PortesPersonalizados: Carriers filtered count: " . count($filtered));

    return $filtered;
}

public function hookDisplayBeforeCarrier($params)
{
    if (!$this->context->cart->id_address_delivery) {
        return '';
    }
    $address = new Address($this->context->cart->id_address_delivery);
    $region = $this->getRegionFromPostcode($address->postcode);
    $allowedCarrierId = $this->getCarrierForRegion($region);

    // Auto-select correct carrier if none selected
    if ($allowedCarrierId && !$this->context->cart->id_carrier) {
        $this->context->cart->id_carrier = $allowedCarrierId;
        $this->context->cart->update();
    }
    $this->context->smarty->assign([
        'allowed_carrier_id' => $allowedCarrierId,
        'shipping_region' => $region
    ]);
    return $this->display(__FILE__, 'views/templates/hook/beforeCarrier.tpl');
}

public function hookActionCarrierProcess($params)
{
    if (!isset($params['cart'])) {
        return true;
    }

    $address = new Address($params['cart']->id_address_delivery);
    $region = $this->getRegionFromPostcode($address->postcode);
    $allowedCarrierId = $this->getCarrierForRegion($region);

    // BLOCK CHECKOUT if wrong carrier
    if ($allowedCarrierId && $params['cart']->id_carrier != $allowedCarrierId) {
        $this->context->controller->errors[] = $this->l('Transportadora inválida para sua região');
        return false; // This stops checkout completely
    }

    return true;
}


    // HELPER METHODS

    private function getRegionFromPostcode($postcode)
    {
        $postcode = preg_replace('/[^0-9]/', '', $postcode);
        $prefix = substr($postcode, 0, 2);

        $regions = [
            '90' => 'Açores',
            '98' => 'Madeira',
            '99' => 'Madeira',
            'default' => 'Portugal Continental'
        ];

        return $regions[$prefix] ?? $regions['default'];
    }

    private function getCarriersForRegion($region)
    {
        $allCarriers = Carrier::getCarriers(
            $this->context->language->id,
            true,  // active only
            false, // include deleted
            false, // id_zone
            null,  // id_group
            true   // return as array
        );

        $carrierMap = [
            'Portugal Continental' => ['CTT - Portugal Continental'],
            'Madeira' => ['CTT - Madeira'],
            'Açores' => ['CTT - Açores']
        ];

        $validIds = [];
        if (!isset($carrierMap[$region])) {
            return $validIds;
        }

        foreach ($carrierMap[$region] as $carrierName) {
            foreach ($allCarriers as $carrier) {
                if ($carrier['name'] === $carrierName) {
                    $validIds[] = $carrier['id_carrier'];
                }
            }
        }
        return $validIds;
    }
}
