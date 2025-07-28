(function(){
    function lockInvalidCarriers() {
        if (!window.allowedCarrierId) return;
        
        document.querySelectorAll('input[name^="delivery_option"]').forEach(radio => {
            const carrierId = parseInt(radio.value.split(',')[0]);
            
            if (carrierId !== window.allowedCarrierId) {
                // Remove invalid options completely
                const parent = radio.closest('.delivery-option');
                if (parent) parent.remove();
            } else {
                // Force-select the valid one
                radio.checked = true;
            }
        });
    }

    // Run immediately and watch for changes
    lockInvalidCarriers();
    new MutationObserver(lockInvalidCarriers).observe(document.body, {
        childList: true,
        subtree: true
    });
})();
