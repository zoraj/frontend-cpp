import QtQuick 2.15
import "qrc:/UI/Dialog"
import "qrc:/UI/Component"
import cloud.mat.frontend 1.0

OrderViewForm {
    property Order order: Order {}
    property OrderDetail orderDetail: OrderDetail {}
    property int orderId: 0
    property int tableNum: 0

    // Dialog Instantiator
    PosProductSearchDialog {
        id: productSearchDialog
    }

    /*
    RestoTopUpDialog {
        id: topUpDialog
    }

    MmcOrderAction {
        height: 100
        id: orderAction
        x: orderDetailListView.x + orderDetailListView.width
        y: orderDetailListView.y
        visible: false
    }*/

    // UI Connections
    Connections {
        target: _orderViewController
        function onViewDidLoadFinished() {
            productGrid.model = _orderViewController.productListProxyModel
            groupProductListView.model = _orderViewController.groupProductListModel
            orderDetailListView.model = _orderViewController.orderDetailListModel
            //topUpDialog.cookingListView.model = _orderViewController.cookingListModel
            //topUpDialog.accompanimentListView.model= _orderViewController.accompanimentListModel
        }
        function onOrderChanged(_order) {
            if (_order.numTable === 0)
                nTableText.text = ""
            else
                nTableText.text = _order.numTable
            nbCouvertText.value = _order.nbCouvert
        }

        function onOrderDetailChanged(grossTotal, vatTotal, netTotal) {
            grossTotalText.text = grossTotal
            vatTotalText.text = vatTotal
            netTotalText.text = netTotal
        }
        function onCheckoutButtonClickFinished(orderId) {
            gMainStackView.push(null, "qrc:/UI/View/OrderCheckoutView.qml", {"orderId": orderId})
        }
    }
    /* --- Product Search Dialog --- */
    Connections {
        target: productSearchDialog
        function onVisibleChanged() {
            if (!productSearchDialog.visible && productSearchDialog.productSelectedId !== -1) {
                let qte = numKeys.value.length > 0 ? parseInt(numKeys.value) : 1
                _orderViewController.productSelected(productSearchDialog.productSelectedId, qte)
                numKeys.clear()
            }
        }
    }

    /* --- Detail Order Action --- */
    /*
    Connections {
        target: orderAction
        function onDeleteButtonClicked(productId) {
            let qty = numKeys.value.length > 0 ? parseInt(numKeys.value) : 1
            _orderViewController.deleteOrderButtonClicked(productId, qty)
            orderAction.visible = false
            numKeys.clear()
        }
        function onOffertButtonClicked(productId) {
            let qty = numKeys.value.length > 0 ? parseInt(numKeys.value) : 1
            _orderViewController.offertOrderButtonClicked(productId, qty)
            orderAction.visible = false
            numKeys.clear()
        }
    }*/

    Component.onCompleted: {
        gShouldServiceChoicePOSVisible = false
        _orderViewController.viewDidLoad()
        //_orderViewController.openOrder(orderId, tableNum)
    }

    // UI events
    checkoutButton.onClicked: {
        if (orderDetailListView.count > 0) {
            _orderViewController.checkoutButtonClicked()
            //order.numTable = nTableText.text.length > 0 ? parseInt(nTableText.text) : 0
            //order.nbCouvert = parseInt(nbCouvertText.value)
        }
        else {
            gMainToast.start("Il n'y a rien à encaisser")
        }
    }

    productSearchButton.onClicked: {
        productSearchDialog.productSelectedId = -1
        productSearchDialog.open()
    }

    topUpButton.onClicked: {
        topUpDialog.open()
    }

    quitButton.onClicked: {
        order.numTable = nTableText.text.length > 0 ? parseInt(nTableText.text) : 0
        order.nbCouvert = parseInt(nbCouvertText.value)

        _orderViewController.quitButtonClicked()
        gMainToast.start("La note a été enregistrée")
    }
    ticketButton.onClicked: {
        gMainToast.start("Impression ticket lancée")
        _orderViewController.ticketButtonClicked()
    }
    invoiceButton.onClicked: {
        gMainToast.start("Impression facture")
    }


    // UI Events for keyboard
    /* Group product UI event */
    function groupProductSelected(productGroupId) {
        _orderViewController.groupProductSelected(productGroupId)
    }

    /* Product Events */
    function productCellSelected(productId) {
        let qte = numKeys.value.length > 0 ? parseInt(numKeys.value) : 1
        _orderViewController.productSelected(productId, qte)
        numKeys.clear()
    }

    // UI Functions
    function detailOrderSelected(productId) {
        orderAction.visible = true
        orderAction.productId = productId
    }
}
