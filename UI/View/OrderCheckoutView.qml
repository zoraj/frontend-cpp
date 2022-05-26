import QtQuick 2.15

OrderCheckoutViewForm {
    property int orderId: -1
    Connections {
        target: _orderCheckoutViewController
        function onViewDidLoadFinished() {
            cashingModeGrid.model =_orderCheckoutViewController.cashingModeListModel
            orderDetailListView.model = _orderCheckoutViewController.orderDetailListModel
            checkoutListView.model = _orderCheckoutViewController.orderCheckoutListModel;
        }
        function onCashingModeSelectedFinished() {
            gMainToast.start("Encaissement terminé")
            //_orderViewController.resetOrder()
        }

        function onCheckoutDetailChanged(totalAmount) {
            totalRecapCheckoutLabel.text = totalAmount
        }
        function onValidateButtonClickedFinished() {
            gMainToast.start("Encaissement terminé")
            _orderViewController.resetOrder()
            gMainStackView.pop()
        }
    }

    Component.onCompleted: {
        _orderCheckoutViewController.setOrderId(orderId)
        _orderCheckoutViewController.viewDidLoad()
        console.log("New order id " + orderId)
    }

    // UI Events
    validateButton.onClicked: {
        if (checkoutListView.count > 0) {
            _orderCheckoutViewController.validateButtonClicked()
        }
        else {
            gMainToast.start("Veuillez sélectionner un mode d'encaissement.")
        }
    }

    function cashingModeSelected(cashingModeId, amount) {
        let amountSelected = parseFloat(amount)
        _orderCheckoutViewController.cashingModeSelected(cashingModeId, amountSelected)
        /*
        if (checkoutListView.count === 0 && amountSelected <= 0.0) {
            let total = parseFloat("200.00")//totalRecapCheckoutLabel.text)
            _orderCheckoutViewController.cashingModeSelected(cashingModeId, total)
        }
        else {
            _orderCheckoutViewController.cashingModeSelected(cashingModeId, amount)
        }*/

        numKeys.clear()
    }
}
