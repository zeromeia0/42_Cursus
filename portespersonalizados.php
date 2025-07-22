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
        $this->version = '1.2.0';
        $this->author = 'Vinicius Vaz';
        $this->need_instance = 0;
        $this->bootstrap = true;

        parent::__construct();

        $this->displayName = $this->l('Portes Personalizados');
        $this->description = $this->l('Calcula portes por região e peso e filtra transportadores por região.');
        $this->confirmUninstall = $this->l('Tem certeza que quer desinstalar?');
    }

    public function install()
    {
        return parent::install() &&
            $this->registerHook('actionCarrierProcess') &&
            $this->registerHook('displayCarrierList') &&
            $this->createDatabaseTable();
    }

    public function uninstall()
    {
        return parent::uninstall() && $this->dropDatabaseTable();
    }

    private function createDatabaseTable()
    {
        $sql = 'CREATE TABLE IF NOT EXISTS `'._DB_PREFIX_.'pp_shipping_prices` (
            `id_pp_shipping_prices` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
            `region` varchar(64) NOT NULL,
            `weight_min` float NOT NULL,
            `weight_max` float NOT NULL,
            `price_normal` decimal(10,2) NOT NULL,
            PRIMARY KEY (`id_pp_shipping_prices`)
        ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;';

        return Db::getInstance()->execute($sql);
    }

    private function dropDatabaseTable()
    {
        return Db::getInstance()->execute('DROP TABLE IF EXISTS `'._DB_PREFIX_.'pp_shipping_prices`');
    }

    public function hookActionCarrierProcess($params)
    {
        $cart = $params['cart'];
        $total_weight = (float)$cart->getTotalWeight();
        $address = new Address((int)$cart->id_address_delivery);
        $region = $this->getRegionFromPostalCode($address->postcode) ?: 'Portugal Continental';
        
        if ($price = $this->getShippingPriceByWeightAndRegion($region, $total_weight)) {
            $params['shipping_cost'] = (float)$price;
        } else {
            $params['shipping_cost'] = 0;
        }

        return $params;
    }

    public function hookDisplayCarrierList($params)
    {
        $address = new Address((int)Context::getContext()->cart->id_address_delivery);
        $region = $this->getRegionFromPostalCode($address->postcode);
        
        $carrierMap = [
            'Portugal Continental' => 'CTT - Portugal Continental',
            'Madeira' => 'CTT - Madeira',
            'Açores' => 'CTT - Açores'
        ];

        if (!isset($carrierMap[$region])) {
            return '';
        }

        $carrierId = (int)Carrier::getIdByName($carrierMap[$region]);
        if (!$carrierId) {
            return '';
        }

        return '
        <script>
        $(document).ready(function() {
            var correctId = '.$carrierId.';
            $(".delivery-option").each(function() {
                var carrierId = $(this).data("id-carrier") || $(this).find("input").val().split(",")[0];
                $(this).toggle(carrierId == correctId);
            });
            $("input.delivery_option_radio[value=\''.$carrierId.',\']").prop("checked", true).change();
        });
        </script>';
    }

    private function getRegionFromPostalCode($postcode)
    {
        $postcode = preg_replace('/\s+/', '', $postcode);
        
        if (preg_match('/^9[0-9]{3}/', $postcode)) {
            return 'Açores';
        } elseif (preg_match('/^98[0-9]{2}/', $postcode) || preg_match('/^99[0-9]{2}/', $postcode)) {
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
            AND '.$weight.' BETWEEN weight_min AND weight_max
            LIMIT 1
        ');
    }
}
