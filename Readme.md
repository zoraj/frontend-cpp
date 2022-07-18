#QML Structure

/* Component Initilization - Start */
Connections {

}

Component.onCompleted: {

}
/* Component Initilization - End */

/* Event Logic */


#CPP Structure

/* Constructor And Destructor - Start */

/* Constructor And Destructor - End */


/* Private Methods - Start */

/* Private Methods - End */


/* Public Methods - Start */

/* Public Methods - End */


/* UI Logic - Start */

/* UI Logic - End */


Doxygen standard comment
/*!
 * @brief ... text ...
 * @detail
 *
 *
 * @param
 * @param
 * @return
 */
 


/*!
 *  @file ApplicationManager.h
 *  @brief This header file will be useful for the doxygen.
 *
 *  @author Author <email>
 *  @date
 */





--------------------------------------------------------------
Difference between Q_INVOKABLE and Public slots
Usecase Q_INVOKABLE 
Methods marked as Q_INVOKABLE are used for BaseViewController override methods
eg.
Q_INVOKABLE
void viewDidLoad() override;
Q_INVOKABLE
void viewDidUnload() override;


Usecase Slots
Slots are used as UI event such as button clicked, combobox selected
Naming convention eg.
void validateButton_Clicked();


------------------------------------------------------------------
QML Background colour is grey
QML User interaction component colour is white



Coding convention
class member
int myMember_
