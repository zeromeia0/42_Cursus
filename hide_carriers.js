(function(){
  function processCarrierOptions() {
    if (!window.allowedCarrierIds || !Array.isArray(window.allowedCarrierIds)) return;
    
    // Try different selectors for different themes
    var selectors = [
      '.delivery-option input[type="radio"]', // Default theme
      '.carrier-item input[type="radio"]',    // Some custom themes
      '.delivery-method-option input[type="radio"]' // Others
    ];
    
    var found = false;
    selectors.forEach(function(selector) {
      if (found) return;
      
      var radios = document.querySelectorAll(selector);
      if (radios.length > 0) {
        found = true;
        
        // Auto-select the correct carrier if specified
        if (window.autoSelectCarrierId) {
          var correctOption = document.querySelector('input[type="radio"][value^="' + window.autoSelectCarrierId + ',"]');
          if (correctOption && !correctOption.checked) {
            correctOption.checked = true;
            correctOption.dispatchEvent(new Event('change'));
          }
        }
        
        // Disable invalid options
        radios.forEach(function(radio) {
          var carrierId = parseInt(radio.value.split(',')[0]);
          if (carrierId && window.allowedCarrierIds.indexOf(carrierId) === -1) {
            radio.disabled = true;
            // Also disable the parent container for visual feedback
            var parent = radio.closest('.delivery-option, .carrier-item, .delivery-method-option');
            if (parent) {
              parent.style.opacity = '0.6';
              parent.style.pointerEvents = 'none';
            }
          }
        });
      }
    });
  }

  // Run immediately and on relevant events
  processCarrierOptions();
  document.addEventListener('DOMContentLoaded', processCarrierOptions);
  document.body.addEventListener('updatedDeliveryForm', processCarrierOptions);
  
  // Watch for dynamic changes
  new MutationObserver(processCarrierOptions).observe(document.body, {
    childList: true,
    subtree: true
  });
})();
