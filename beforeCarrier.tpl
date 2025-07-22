{if $portes_region}
<div class="portes-region-info alert alert-info">
    {l s='Shipping to' mod='portespersonalizados'} {$portes_region} {l s='with postal code' mod='portespersonalizados'} {$portes_postcode}
</div>
{/if}

{if $carrier_error}
<div class="alert alert-danger">{$carrier_error}</div>
{/if}

<script>
$(document).ready(function() {
    // Backup JS filtering
    $('.delivery-option').hide();
    $('.delivery-option:contains("{$portes_region}")').show();
});
</script>
