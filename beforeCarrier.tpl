{if $portes_region}
<div class="portes-region-info alert alert-info">
    {l s='Shipping to' mod='portespersonalizados'} {$portes_region} {l s='with postal code' mod='portespersonalizados'} {$portes_postcode}
</div>
{/if}

{if $carrier_error}
<div class="alert alert-danger">{$carrier_error}</div>
{/if}

<script>
// Backup filtering for PS 1.7+ themes
$(document).ready(function() {
    var region = "{$portes_region|escape:'javascript':'UTF-8'}";
    var carrierMap = {
        'Portugal Continental': 'Portugal Continental',
        'Madeira': 'Madeira',
        'Açores': 'Açores'
    };
    
    if (carrierMap[region]) {
        // Hide all first
        $('.delivery-option').hide();
        
        // Show matching carriers
        $('.delivery-option').each(function() {
            if ($(this).text().indexOf(carrierMap[region]) > -1) {
                $(this).show();
                // Auto-select the first valid option
                $(this).find('input[type=radio]').prop('checked', true).trigger('change');
            }
        });
    }
});
</script>
