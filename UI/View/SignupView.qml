import QtQuick 2.15
//import cloud.multimicro.mmc.frontend 1.0
import "qrc:/UI/Script/Countries.js" as CountryJS


SignupViewForm {
    //property Establishment establishment: Establishment{}

    // Business Component Initialization
    Connections {
        /*
        target: _signupViewController
        onSignupCallback: {
            if (result) {
                mainToast.show("Creation d'un nouveau compte avec succès.");
                mainStackView.push("/View/Common/CodeConfirmationView.qml")
            }
        }*/
    }

    // UI Component Initialization
    ListModel {
        id: typeEstablishmentModel
        ListElement { value: "Restaurant"; key: "R"}
        ListElement { value: "Hotel"; key: "H"}
        ListElement { value: "Restaurant et Hotel"; key: "HR"}
        ListElement { value: "Restauration collective"; key: "COL"}
    }

    typeComboBox {
        model: typeEstablishmentModel
        role: "value"
    }
    countryComboBox {
        model: CountryJS.getCountries();
        role: "name"
    }

    // View Load
    Component.onCompleted: {

    }

    // Event Logic
    validateButton.onClicked: {
        /*
        establishment.name = nameTextField.text
        establishment.email = nameTextField.text
        establishment.type = typeEstablishmentModel.get(typeComboBox.currentIndex).value
        establishment.country = CountryJS.getCountryCode(countryComboBox.currentIndex)

        if (nameTextField.text.trim().length > 0 || addressTextField.text.trim().length > 0 || ownerFirstnameTextField.text.trim().length > 0 || email1TextField.text.trim().length > 0 || phoneTextField.text.trim().length > 0) {
            establishment.name = nameTextField.text
            establishment.address = addressTextField.text
            establishment.ownerFirstName = ownerFirstnameTextField.text
            establishment.ownerLastName = ownerLastnameTextField.text
            establishment.email = email1TextField.text
            establishment.phone = phoneTextField.text
            establishment.type = typeEstablishmentModel.get(typeComboBox.currentIndex).key
            establishment.country = CountryJS.getCountryCode(countryComboBox.currentIndex)
            _signupViewController.validateButtonClicked(establishment)
            //mainStackView.push("/View/Common/CodeConfirmationView.qml")
        }
        else {
            //popupToast.start(qsTr("Champs obligatoires non renseignés"))
        }*/
    }

    activateDeviceButton.onClicked: {
        gMainStackView.push("/UI/View/CodeConfirmationView.qml")
    }
}
