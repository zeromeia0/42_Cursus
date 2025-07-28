(function(){
  function hideUnwantedCarriers() {
    if (!window.allowedCarrierIds || !Array.isArray(window.allowedCarrierIds)) return;

    // Try different selectors - PrestaShop themes vary
    var selectors = [
      '.delivery-options .delivery-option', // Default theme
      '.carrier-container .carrier-item',   // Some custom themes
      '#delivery-methods .delivery-method'   // Other themes
    ];

    var carrierOptions = null;
    for (var i = 0; i < selectors.length; i++) {
      carrierOptions = document.querySelectorAll(selectors[i]);
      if (carrierOptions.length > 0) break;
    }

    if (!carrierOptions || carrierOptions.length === 0) {
      console.error('PortesPersonalizados: Could not find carrier options');
      return;
    }

    carrierOptions.forEach(function(option){
      var radio = option.querySelector('input[type=radio][name^="delivery_option"]');
      if (!radio) return;

      var value = radio.value;
      var carrierId = parseInt(value, 10); // Try simple parseInt first

      // If that fails, try regex
      if (isNaN(carrierId)) {
        var matches = value.match(/^(\d+)/);
        carrierId = matches ? parseInt(matches[1], 10) : null;
      }

      if (carrierId && window.allowedCarrierIds.indexOf(carrierId) === -1) {
        option.style.display = 'none';
      }
    });
  }

  // Run immediately and also on events
  hideUnwantedCarriers();
  document.addEventListener('DOMContentLoaded', hideUnwantedCarriers);
  document.body.addEventListener('updatedDeliveryForm', hideUnwantedCarriers);
  // Add mutation observer for dynamic changes
  new MutationObserver(hideUnwantedCarriers).observe(document.body, {
    childList: true,
    subtree: true
  });
})();
