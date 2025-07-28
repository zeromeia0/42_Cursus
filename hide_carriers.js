document.addEventListener('DOMContentLoaded', function () {
    // Get allowed carrier ID passed from Smarty as global JS variable 'allowed_carrier_id'
    var allowedCarrierId = parseInt(window.allowed_carrier_id || 0);
    if (!allowedCarrierId) {
        // No allowed carrier set - do nothing
        return;
    }

    // Find the continue button in checkout (replace selector with the actual one on your theme)
    var continueButton = document.querySelector('.cart-done a.cart-done-button, button[name="confirmDeliveryOption"], .checkout-btn');

    // If cannot find button with those selectors, fallback to common ones, or warn
    if (!continueButton) {
        console.warn('Continue button not found by JS in hide_carriers.js');
    }

    // Get all carrier radio inputs
    var carrierRadios = document.querySelectorAll('input[name="id_carrier"]');

    function checkCarrierSelection() {
        var selected = document.querySelector('input[name="id_carrier"]:checked');
        if (!selected) {
            // No selection, disable continue
            if (continueButton) {
                continueButton.disabled = true;
            }
            return;
        }

        var selectedId = parseInt(selected.value);

        if (selectedId !== allowedCarrierId) {
            if (continueButton) {
                continueButton.disabled = true;

                // Optionally show alert only once per invalid selection:
                if (!window._invalidCarrierAlertShown) {
                    alert('Transportadora inválida para sua região');
                    window._invalidCarrierAlertShown = true;
                }
            }
        } else {
            if (continueButton) {
                continueButton.disabled = false;
            }
            window._invalidCarrierAlertShown = false;
        }
    }

    carrierRadios.forEach(function (radio) {
        radio.addEventListener('change', checkCarrierSelection);
    });

    // Initial check on page load
    checkCarrierSelection();
});
