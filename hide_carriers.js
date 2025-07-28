(function(){
  function hideUnwantedCarriers() {
    if (!window.allowedCarrierIds || !Array.isArray(window.allowedCarrierIds)) return;

    // Adjust selector if your theme is different
    var carrierOptions = document.querySelectorAll('.delivery-options .delivery-option');

    carrierOptions.forEach(function(option){
      var radio = option.querySelector('input[type=radio][name^="delivery_option"]');
      if (!radio) return;

      var value = radio.value;
      var matches = value.match(/^(\d+)/);
      var carrierId = matches ? parseInt(matches[1], 10) : null;

      if (carrierId && window.allowedCarrierIds.indexOf(carrierId) === -1) {
        option.style.display = 'none';
      }
    });
  }

  document.addEventListener('DOMContentLoaded', hideUnwantedCarriers);
  document.body.addEventListener('updatedDeliveryForm', hideUnwantedCarriers); // PrestaShop emits AJAX update event
})();
