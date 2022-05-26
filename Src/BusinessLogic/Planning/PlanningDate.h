#pragma once

#include <QDate>
#include "Src/Application/Util/Constant.h"

using namespace constant;

struct PlanningDate
{
    int index = UNDEFINED_INT;
    QDate date;
    bool isWeekEnd = false;
};
