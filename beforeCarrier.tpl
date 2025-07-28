<div class="alert alert-info portes-shipping-info">
    {l s='Shipping to' mod='portespersonalizados'} <strong>{$shipping_region}</strong>
    {l s='for postal code' mod='portespersonalizados'} <strong>{$shipping_postcode}</strong>
</div>

<script>
    window.allowedCarrierIds = {$allowed_carrier_ids|@json_encode nofilter};
</script>
