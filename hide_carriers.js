(function(){
    function lockCarriers() {
        if (!window.allowedCarrierId) return;
        
        document.querySelectorAll('input[name^="delivery_option"]').forEach(radio => {
            const carrierId = parseInt(radio.value.split(',')[0]);
            
            if (carrierId !== window.allowedCarrierId) {
                // Disable the radio button
                radio.disabled = true;
                
                // Gray out the entire option
                const option = radio.closest('.delivery-option, .carrier-item');
                if (option) {
                    option.style.opacity = '0.5';
                    option.style.pointerEvents = 'none';
                    option.querySelector('input').disabled = true;
                }
            } else {
                // Auto-select the correct carrier
                if (!radio.checked) {
                    radio.checked = true;
                    radio.dispatchEvent(new Event('change'));
                }
            }
        });
    }

    // Run immediately and whenever the page changes
    lockCarriers();
    document.addEventListener('DOMContentLoaded', lockCarriers);
    new MutationObserver(lockCarriers).observe(document.body, {
        childList: true,
        subtree: true
    });
})();
