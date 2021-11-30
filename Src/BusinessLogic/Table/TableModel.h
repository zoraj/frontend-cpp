#pragma once
#include "Src/Application/Util/Constant.h"

struct TableModel {
    int numTable;
    bool isAvailable = true;
    int orderId = Constant::UNDEFINED_INT;
};
