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
        $this->version = '2.0.0';
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
            return $carriers;
        }

        $address = new Address($this->context->cart->id_address_delivery);
        $region = $this->getRegionFromPostcode($address->postcode);

        $allowedCarriers = $this->getCarriersForRegion($region);

        return array_filter($carriers, function($carrier) use ($allowedCarriers) {
            return in_array($carrier['id_carrier'], $allowedCarriers);
        });
    }

public function hookActionCarrierProcess($params)
{
    // 1. Bypass completo para testes (descomente apenas para debug)
    // return true;

    // 2. Versão de produção (ativa quando o bypass estiver comentado)
    if (!isset($params['cart'])) {
        return true;
    }

    $cart = $params['cart'];
    
    // Se não houver endereço, não bloqueie o checkout
    if (!$cart->id_address_delivery) {
        return true;
    }

    try {
        $address = new Address($cart->id_address_delivery);
        $region = $this->getRegionFromPostcode($address->postcode);
        $validCarriers = $this->getCarriersForRegion($region);

        // Se não encontrar carriers válidos, permita continuar
        if (empty($validCarriers)) {
            return true;
        }

        // Verifica se o carrier selecionado é válido
        if (!in_array($cart->id_carrier, $validCarriers)) {
            $this->context->controller->errors[] = $this->l('Transportadora inválida para sua região');
            return false;
        }

        return true;

    } catch (Exception $e) {
        // Em caso de erro, não quebre o checkout
        PrestaShopLogger::addLog('PortesPersonalizados Error: '.$e->getMessage(), 3);
        return true;
    }
    }

    public function hookDisplayBeforeCarrier($params)
    {
        if (!$this->context->cart->id_address_delivery) {
            return '';
        }

        $address = new Address($this->context->cart->id_address_delivery);
        $this->context->smarty->assign([
            'shipping_region' => $this->getRegionFromPostcode($address->postcode),
            'shipping_postcode' => $address->postcode
        ]);

        return $this->display(__FILE__, 'views/templates/hook/displayBeforeCarrier.tpl');
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
    error_log("==== DEBUGGING CARRIERS ====");
    error_log("Requested region: ".$region);
    
    $allCarriers = Carrier::getCarriers(
        $this->context->language->id,
        true, // active only
        false, // include deleted
        false, // id_zone
        null,  // id_group
        true   // return name with ID
    );
    
    error_log("All available carriers:");
    error_log(print_r($allCarriers, true));
    
    $carrierMap = [
        'Portugal Continental' => ['CTT - Portugal Continental'],
        'Madeira' => ['CTT - Madeira'],
        'Açores' => ['CTT - Açores']
    ];
    
    $validIds = [];
    foreach ($carrierMap[$region] as $carrierName) {
        $id = Carrier::getIdByName($carrierName);
        error_log("Checking carrier: ".$carrierName." => ID: ".$id);
        if ($id) $validIds[] = $id;
    }
    
    error_log("Valid IDs for region: ".print_r($validIds, true));
    return $validIds;
    }
}
