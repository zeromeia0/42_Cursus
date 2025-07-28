<?php
class PortesPersonalizados extends Module
{
    public function __construct()
    {
        $this->name = 'portespersonalizados';
        $this->tab = 'shipping_logistics';
        $this->version = '5.6.7';
        $this->author = 'Vinicius Vaz';
        $this->need_instance = 0;
        $this->bootstrap = true;
        
        parent::__construct();
        $this->displayName = $this->l('Region Locked Shipping');
        $this->description = $this->l('Locks carriers to specific postal code regions');
    }

    public function install()
    {
        return parent::install() && 
            $this->registerHook('displayBeforeCarrier');
    }

    public function hookDisplayBeforeCarrier($params)
    {
        if (!$this->context->cart->id_address_delivery) {
            return '';
        }

        $address = new Address($this->context->cart->id_address_delivery);
        $region = $this->getRegionFromPostcode($address->postcode);
        $allowedCarrierId = $this->getCarrierForRegion($region);

        $this->context->smarty->assign([
            'allowed_carrier_id' => $allowedCarrierId,
            'shipping_region' => $region
        ]);

        $this->context->controller->addJS($this->_path.'views/js/hide_carriers.js');
        return $this->display(__FILE__, 'views/templates/hook/beforeCarrier.tpl');
    }

    private function getRegionFromPostcode($postcode)
    {
        $prefix = substr(preg_replace('/[^0-9]/', '', $postcode), 0, 2);
        return match($prefix) {
            '90' => 'Açores',
            '98', '99' => 'Madeira',
            default => 'Portugal Continental'
        };
    }

    private function getCarrierForRegion($region)
    {
        $carriers = Carrier::getCarriers(
            $this->context->language->id,
            true,
            false,
            false,
            null,
            ALL_CARRIERS
        );

        $regionCarriers = [
            'Portugal Continental' => 'CTT - Portugal Continental',
            'Madeira' => 'CTT - Madeira',
            'Açores' => 'CTT - Açores'
        ];

        foreach ($carriers as $carrier) {
            if ($carrier['name'] === $regionCarriers[$region]) {
                return $carrier['id_carrier'];
            }
        }
        return null;
    }
}
