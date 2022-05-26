#pragma once

#include "Src/Application/Base/BaseViewController.h"
#include "Src/Application/Util/Constant.h"
#include "Src/BusinessLogic/Order/OrderService.h"
#include "Src/BusinessLogic/Order/OrderCache.h"
#include "Src/BusinessLogic/Order/OrderBuilder.h"
#include "ActivityCache.h"
#include "Src/BusinessLogic/Table/Table.h"
#include "Src/BusinessLogic/Table/TablePlanListModel.h"
#include "ActivityListModel.h"
#include "Src/BusinessLogic/Order/OrderListModel.h"

class ActivitiesViewController : public BaseViewController
{
    Q_OBJECT
    Q_PROPERTY(ActivityListModel* activityListModel MEMBER activityListModel)
    Q_PROPERTY(OrderListModel* openOrderListModel MEMBER openOrderListModel)
    Q_PROPERTY(TablePlanListModel* tablePlanListModel MEMBER tablePlanListModel)

    ActivityListModel* activityListModel;
    OrderListModel* openOrderListModel;
    TablePlanListModel* tablePlanListModel;

    void loadData();
    void loadTableData(int activityId);
    Activity getActivityById(int activityId);
public:
    ActivitiesViewController(QObject *parent = nullptr);

    void viewDidLoad() override;
    void viewDidUnload() override;

    //Q_INVOKABLE
    //void newNoteButtonClicked(int activityId, const QString &numTable);

signals:
    void viewDidLoadFinished(const QString &username);
public slots:
    void openNoteButton_Clicked(int activityId);
    void newNoteButton_Clicked(int activityId);
    void tablePlanButton_Clicked(int activityId);
    void toggleService(const QString &service);
};

