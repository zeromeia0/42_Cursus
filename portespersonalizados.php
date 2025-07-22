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
        $this->version = '1.5.2';
        $this->author = 'Vinicius Vaz';
        $this->need_instance = 0;
        $this->bootstrap = true;
        $this->ps_versions_compliancy = ['min' => '1.7', 'max' => _PS_VERSION_];

        parent::__construct();

        $this->displayName = $this->l('Custom Shipping');
        $this->description = $this->l('Region-based carrier filtering and shipping costs');
        $this->confirmUninstall = $this->l('Are you sure you want to uninstall?');
    }

    public function install()
    {
        return parent::install() &&
            $this->registerHook('filterCarrierList') &&
            $this->registerHook('displayBeforeCarrier') &&
            $this->registerHook('actionCarrierProcess') &&
            $this->createDatabaseTable() &&
            $this->installDemoData();
    }

    public function uninstall()
    {
        return parent::uninstall() && 
            $this->dropDatabaseTable();
    }

    private function createDatabaseTable()
    {
        $sql = 'CREATE TABLE IF NOT EXISTS `'._DB_PREFIX_.'pp_shipping_prices` (
            `id_pp_shipping_prices` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
            `region` varchar(64) NOT NULL,
            `weight_min` float NOT NULL DEFAULT 0,
            `weight_max` float NOT NULL DEFAULT 9999,
            `price_normal` decimal(10,2) NOT NULL DEFAULT 0,
            PRIMARY KEY (`id_pp_shipping_prices`),
            KEY `region` (`region`),
            KEY `weight_range` (`weight_min`, `weight_max`)
        ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;';

        return Db::getInstance()->execute($sql);
    }

    private function installDemoData()
    {
        $sampleData = [
            ['Portugal Continental', 0, 5, 5.00],
            ['Portugal Continental', 5, 10, 7.50],
            ['Portugal Continental', 10, 20, 10.00],
            ['Madeira', 0, 5, 8.00],
            ['Madeira', 5, 10, 12.00],
            ['Madeira', 10, 20, 16.00],
            ['Açores', 0, 5, 10.00],
            ['Açores', 5, 10, 15.00],
            ['Açores', 10, 20, 20.00],
        ];

        foreach ($sampleData as $data) {
            Db::getInstance()->insert('pp_shipping_prices', [
                'region' => pSQL($data[0]),
                'weight_min' => (float)$data[1],
                'weight_max' => (float)$data[2],
                'price_normal' => (float)$data[3]
            ]);
        }

        return true;
    }

    private function dropDatabaseTable()
    {
        return Db::getInstance()->execute('DROP TABLE IF EXISTS `'._DB_PREFIX_.'pp_shipping_prices`');
    }

    public function hookFilterCarrierList($carriers)
    {
        // 1. Get current postal code
        $cart = $this->context->cart;
        if (!$cart || !$cart->id_address_delivery) {
            return $carriers; // Fallback
        }

        $address = new Address((int)$cart->id_address_delivery);
        $region = $this->getRegionFromPostalCode($address->postcode);

        // 2. Define carrier mapping
        $carrierMap = [
            'Portugal Continental' => ['CTT - Portugal Continental'],
            'Madeira' => ['CTT - Madeira'],
            'Açores' => ['CTT - Açores']
        ];

        // 3. Filter carriers
        $allowedCarriers = [];
        foreach ($carriers as $carrier) {
            foreach ($carrierMap[$region] ?? [] as $validName) {
                if (strpos($carrier['name'], $validName) !== false) {
                    $allowedCarriers[] = $carrier;
                    break;
                }
            }
        }

        return $allowedCarriers ?: $carriers; // Fallback to all if none match
    }

public function hookDisplayBeforeCarrier($params)
{
    // 1. Get address data
    $cart = $this->context->cart;
    $address = new Address((int)$cart->id_address_delivery);
    
    // 2. Detect region
    $region = $this->getRegionFromPostalCode($address->postcode);
    
    // 3. Assign template variables
    $this->context->smarty->assign([
        'portes_region' => $region,
        'portes_postcode' => $address->postcode,
        'carrier_error' => Tools::getValue('error') == 'invalid_carrier' 
            ? $this->l('Please select a carrier valid for your region') 
            : null
    ]);
    
    // 4. Render template
    return $this->display(__FILE__, 'views/templates/hook/beforeCarrier.tpl');
}

    public function hookActionCarrierProcess($params)
    {
        if (!isset($params['cart'])) {
            return;
        }

        $selectedCarrierId = (int)$params['cart']->id_carrier;
        $validCarrierIds = array_column($this->getValidCarriers(), 'id_carrier');

        if (!empty($validCarrierIds) && !in_array($selectedCarrierId, $validCarrierIds)) {
            Tools::redirect($this->context->link->getPageLink('order', true, null, [
                'step' => 2,
                'error' => 'invalid_carrier'
            ]));
        }
    }

    private function getValidCarriers()
    {
        $cart = $this->context->cart;
        if (!$cart || !$cart->id_address_delivery) {
            return [];
        }

        $address = new Address((int)$cart->id_address_delivery);
        $region = $this->getRegionFromPostalCode($address->postcode);

        $carrierMap = [
            'Portugal Continental' => ['CTT - Portugal Continental'],
            'Madeira' => ['CTT - Madeira'],
            'Açores' => ['CTT - Açores']
        ];

        $validCarriers = [];
        foreach (Carrier::getCarriers($this->context->language->id) as $carrier) {
            foreach ($carrierMap[$region] ?? [] as $validName) {
                if (strpos($carrier['name'], $validName) !== false) {
                    $validCarriers[] = $carrier;
                }
            }
        }

        return $validCarriers;
    }

    private function getRegionFromPostalCode($postcode)
    {
        // Clean input
        $postcode = preg_replace('/[^0-9]/', '', $postcode);
        
        // Hardcoded fallback
        if (preg_match('/^9[0-9]{3}/', $postcode)) {
            return 'Açores';
        } elseif (preg_match('/^(98|99)[0-9]{2}/', $postcode)) {
            return 'Madeira';
        }

        return 'Portugal Continental';
    }

    private function getShippingPriceByWeightAndRegion($region, $weight)
    {
        return (float)Db::getInstance()->getValue('
            SELECT price_normal 
            FROM '._DB_PREFIX_.'pp_shipping_prices
            WHERE region = "'.pSQL($region).'"
            AND '.$weight.' >= weight_min 
            AND '.$weight.' < weight_max
            ORDER BY weight_min ASC
            LIMIT 1
        ');
    }
}
