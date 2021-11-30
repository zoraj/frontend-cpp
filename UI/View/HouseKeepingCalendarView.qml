import QtQuick 2.15

HouseKeepingCalendarViewForm {

    Component.onCompleted: {
        gModule = 3
    }


    function getMaidList(cDate) {
        //console.log(cDate)
        return "Jean Onari"
    }

    function isDateWeekend(cDate) {
        var day = cDate.getDay();
        var isWeekend = (day === 6) || (day === 0);    // 6 = Saturday, 0 = Sunday
        return isWeekend;
    }
    function isToday(cDate) {
        const today = new Date();
        return cDate.getDate() === today.getDate();
    }
}
