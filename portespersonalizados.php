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
        $this->version = '1.3.0';
        $this->author = 'Vinicius Vaz';
        $this->need_instance = 0;
        $this->bootstrap = true;
        $this->ps_versions_compliancy = ['min' => '1.7', 'max' => _PS_VERSION_];

        parent::__construct();

        $this->displayName = $this->l('Portes Personalizados');
        $this->description = $this->l('Calcula portes por região e peso e filtra transportadores por região.');
        $this->confirmUninstall = $this->l('Tem certeza que quer desinstalar?');
    }

    public function install()
    {
        return parent::install() &&
            $this->registerHook('actionCarrierProcess') &&
            $this->registerHook('displayBeforeCarrier') &&
            $this->registerHook('filterCarrierList') &&
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
        // Sample data for Portugal Continental
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

    public function hookActionCarrierProcess($params)
    {
        if (!isset($params['cart'])) {
            return;
        }

        $cart = $params['cart'];
        $total_weight = (float)$cart->getTotalWeight();
        
        try {
            $address = new Address((int)$cart->id_address_delivery);
            $region = $this->getRegionFromPostalCode($address->postcode) ?: 'Portugal Continental';
            
            $price = $this->getShippingPriceByWeightAndRegion($region, $total_weight);
            $params['shipping_cost'] = (float)$price;
        } catch (Exception $e) {
            PrestaShopLogger::addLog('PortesPersonalizados error: '.$e->getMessage(), 3);
            $params['shipping_cost'] = 0;
        }

        return $params;
    }

    public function hookFilterCarrierList($carriers)
    {
        $cart = Context::getContext()->cart;
        if (!$cart || !$cart->id_address_delivery) {
            return $carriers;
        }

        try {
            $address = new Address((int)$cart->id_address_delivery);
            $region = $this->getRegionFromPostalCode($address->postcode);
            
            $carrierMap = [
                'Portugal Continental' => 'CTT - Portugal Continental',
                'Madeira' => 'CTT - Madeira',
                'Açores' => 'CTT - Açores'
            ];

            if (!isset($carrierMap[$region])) {
                return $carriers;
            }

            $targetCarrierName = $carrierMap[$region];
            $filteredCarriers = [];

            foreach ($carriers as $carrier) {
                if (strpos($carrier['name'], $targetCarrierName) !== false) {
                    $filteredCarriers[] = $carrier;
                }
            }

            return $filteredCarriers ?: $carriers;
        } catch (Exception $e) {
            PrestaShopLogger::addLog('PortesPersonalizados filter error: '.$e->getMessage(), 3);
            return $carriers;
        }
    }

public function hookDisplayBeforeCarrier($params)
{
    try {
        $cart = Context::getContext()->cart;
        if (!$cart || !$cart->id_address_delivery) {
            return '';
        }

        $address = new Address((int)$cart->id_address_delivery);
        $region = $this->getRegionFromPostalCode($address->postcode);
        
        return '
        <div class="portes-region-info alert alert-info">
            '.$this->l('Shipping to').' '.$region.' '.$this->l('with postal code').' '.$address->postcode.'
        </div>';
    } catch (Exception $e) {
        PrestaShopLogger::addLog('PortesPersonalizados display error: '.$e->getMessage(), 3);
        return '';
    }
}

    private function getRegionFromPostalCode($postcode)
    {
        if (empty($postcode)) {
            return 'Portugal Continental';
        }

        $postcode = preg_replace('/[^0-9]/', '', $postcode);
        
        if (strlen($postcode) < 4) {
            return 'Portugal Continental';
        }

        $prefix = substr($postcode, 0, 2);
        $firstDigit = substr($postcode, 0, 1);

        // Açores: 9000-9999 (but 9800-9999 are Madeira)
        if ($firstDigit == '9') {
            if ($prefix == '98' || $prefix == '99') {
                return 'Madeira';
            }
            return 'Açores';
        }

        return 'Portugal Continental';
    }

    private function getShippingPriceByWeightAndRegion($region, $weight)
    {
        $weight = (float)$weight;
        $region = pSQL($region);

        return (float)Db::getInstance()->getValue('
            SELECT price_normal 
            FROM '._DB_PREFIX_.'pp_shipping_prices
            WHERE region = "'.$region.'"
            AND '.$weight.' >= weight_min 
            AND '.$weight.' < weight_max
            ORDER BY weight_min ASC
            LIMIT 1
        ');
    }
}
