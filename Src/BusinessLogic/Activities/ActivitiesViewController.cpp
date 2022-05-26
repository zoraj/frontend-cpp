#include "ActivitiesViewController.h"

// Private methods
void ActivitiesViewController::loadData()
{
    auto activities = cache::activity::getAll();
    activityListModel->list = activities;

    auto currentActivity = ApplicationManager::getInstance()->getAppContext()->currentActivity;
    if (currentActivity != constant::UNDEFINED_INT) {
        auto orders = cache::order::getByActivity(currentActivity);
        openOrderListModel->setList(orders);
    }
}

void ActivitiesViewController::loadTableData(int activityId)
{
    // Load existing orders
    auto orders = cache::order::getByActivity(ApplicationManager::getInstance()->getAppContext()->currentActivity);

    auto activity = getActivityById(activityId);
    QList<Table> tables;
    for(int i = 1; i <= activity.nombreTable; ++i) {
        Table table;
        table.isAvailable = true;
        table.orderId = constant::UNDEFINED_INT;
        // For every table, look at orders if any
        foreach(auto order, orders) {
            if (order->numTable == i) {
                table.isAvailable = false;
                table.orderId = order->id;
            }
        }
        table.numTable = i;
        tables.append(table);
    }

    qDebug() << "Tables count " << tables.size();
    tablePlanListModel->setList(tables);
}

Activity ActivitiesViewController::getActivityById(int activityId)
{
    QList<Activity>::iterator activity;
    auto list = activityListModel->list;
    for (activity = list.begin(); activity != list.end(); ++activity) {
        if (activity->id == activityId) {
            return *activity;
        }
    }
    // TODO: Manage when no activity found
}

// Public methods
ActivitiesViewController::ActivitiesViewController(QObject *parent) : BaseViewController(parent)
{
    activityListModel = new ActivityListModel();
    activityListModel->setParent(this);
    openOrderListModel = new OrderListModel();
    openOrderListModel->setParent(this);
    tablePlanListModel = new TablePlanListModel();
    tablePlanListModel->setParent(this);
}

void ActivitiesViewController::viewDidLoad()
{
    loadData();
    QString username = ApplicationManager::getInstance()->getAppContext()->user->firstname + " " + ApplicationManager::getInstance()->getAppContext()->user->lastname;
    emit viewDidLoadFinished(username);
}

void ActivitiesViewController::viewDidUnload()
{

}

void ActivitiesViewController::openNoteButton_Clicked(int activityId)
{
    ApplicationManager::getInstance()->getAppContext()->currentActivity = activityId;
    loadData();
}

void ActivitiesViewController::newNoteButton_Clicked(int activityId)
{
     ApplicationManager::getInstance()->getAppContext()->currentActivity = activityId;
}

void ActivitiesViewController::tablePlanButton_Clicked(int activityId)
{
    ApplicationManager::getInstance()->getAppContext()->currentActivity = activityId;
    loadTableData(activityId);
}

/*
 *
 * Input Service M = Midday, S = Evening
 */
void ActivitiesViewController::toggleService(const QString &service)
{
     ApplicationManager::getInstance()->getAppContext()->currentPOSService = service;
}
