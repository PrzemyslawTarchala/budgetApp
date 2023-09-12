#include "DateAndTimeManager.h"

int DateAndTimeManager::getYear(){
    int year;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = 1900 + ltm-> tm_year;
    return year;
}

int DateAndTimeManager::getMonth(){
    int month;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    month = 1 + ltm-> tm_mon;
    return month;
}

int DateAndTimeManager::getDay(){
    int day;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    day = ltm -> tm_mday;
    return day;
}

int DateAndTimeManager::getNumbersOfDays(int month, int year){

    if(month == 2){
        if(isLeapYear(year)){
            return 29;
        }
        else{
            return 28;
        }
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8|| month == 10 || month == 12)
        return 31;
    else
        return 30;
}

void DateAndTimeManager::getTodaysDate(string &date){
    string day, month, year;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    //year = AuxiliaryMethods::convertIntToString(1900 + ltm-> tm_year);
    year = AuxiliaryMethods::convertIntToString(getYear());
    //month = AuxiliaryMethods::convertIntToString(1 + ltm-> tm_mon);
    month = AuxiliaryMethods::convertIntToString(getMonth());
    //day = AuxiliaryMethods::convertIntToString(ltm -> tm_mday)
    day = AuxiliaryMethods::convertIntToString(getDay());

    if (month.length() == 1){
        month = '0' + month;
    }
    if (day.length() == 1){
        day = '0' + day;
    }
    date = year + month + day;
}

void DateAndTimeManager::specificDateOfTransaction(string &date){
    int day, month, year;
    string strDay, strMonth, strYear;
    do{
        cout << "Enter day: ";
        day = AuxiliaryMethods::getIntNumber();
        cout << "Enter month: ";
        month = AuxiliaryMethods::getIntNumber();
        cout << "Enter year: ";
        year = AuxiliaryMethods::getIntNumber();

        if(isValidDate(day, month, year)){
            cout << "Date is incorrect. Enter again.";
        }
    }while(isValidDate(day, month, year));

    strDay = AuxiliaryMethods::convertIntToString(day);
    strMonth = AuxiliaryMethods::convertIntToString(month);
    strYear = AuxiliaryMethods::convertIntToString(year);

    if (strMonth.length() == 1){
        strMonth = '0' + strMonth;
    }
    if (strDay.length() == 1){
        strDay = '0' + strDay;
    }
    date = strYear + strMonth + strDay;
}

bool DateAndTimeManager::isValidDate(int day, int month, int year){
    if (month < 1 || month > 12){
        return true;
    }
    if (day < 1 || day > 31){
        return true;
    }
    if (month == 2){
        if (isLeapYear(year)){
            if (day > 29){
                 return true;
            }
        }
        else{
            if (day > 28){
                return true;
            }
        }
    }

    if (month == 4 || month == 6 || month == 9 || month == 11){
        if (day <= 30){
            return false;
        }
        else{
            return true;
        }
    }
    return false;
}

bool DateAndTimeManager::isLeapYear (int year){
    if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))){
        return true;
    }
    else return false;
}

void DateAndTimeManager::getTimeFrameForCurrentMonth(int &fromDate, int &toDate){

    int daysInMonth, month, year;
    string strFirstDayOfMonth, strLastDayOfMonth, strMonth, strYear;
    string strFromDate, strToDate;

    year = getYear();
    month = getMonth();
    daysInMonth = getNumbersOfDays(month, year);

    strFirstDayOfMonth = "01";
    strLastDayOfMonth = AuxiliaryMethods::convertIntToString(daysInMonth);
    strMonth = AuxiliaryMethods::convertIntToString(month);
    strYear = AuxiliaryMethods::convertIntToString(year);

    if (strMonth.length() == 1){
        strMonth = '0' + strMonth;
    }
    if (strLastDayOfMonth.length() == 1){
        strLastDayOfMonth = '0' + strLastDayOfMonth;
    }

    strFromDate = strYear + strMonth + strFirstDayOfMonth;
    strToDate = strYear + strMonth + strLastDayOfMonth;

    fromDate = AuxiliaryMethods::convertStringToInt(strFromDate);
    toDate = AuxiliaryMethods::convertStringToInt(strToDate);
}

void DateAndTimeManager::getTimeFrameForPrevoiusMonth(int &fromDate, int &toDate){
    int daysInMonth, month, year;
    string strFirstDayOfMonth, strLastDayOfMonth, strMonth, strYear;
    string strFromDate, strToDate;

    if (getMonth() == 1){
        month = 12;
    }
    else{
        month = getMonth() - 1;
    }

    if(month == 12){
        year = getYear() - 1;
    }
    else{
        year = getYear();
    }
    daysInMonth = getNumbersOfDays(month, year);

    strFirstDayOfMonth = "01";
    strLastDayOfMonth = AuxiliaryMethods::convertIntToString(daysInMonth);
    strMonth = AuxiliaryMethods::convertIntToString(month);
    strYear = AuxiliaryMethods::convertIntToString(year);

    if (strMonth.length() == 1){
        strMonth = '0' + strMonth;
    }
    if (strLastDayOfMonth.length() == 1){
        strLastDayOfMonth = '0' + strLastDayOfMonth;
    }

    strFromDate = strYear + strMonth + strFirstDayOfMonth;
    strToDate = strYear + strMonth + strLastDayOfMonth;

    fromDate = AuxiliaryMethods::convertStringToInt(strFromDate);
    toDate = AuxiliaryMethods::convertStringToInt(strToDate);
}

void DateAndTimeManager::getTimeFrameSpecificByUser(int &fromDate, int &toDate){

    int startDay, startMonth, startYear;
    int endDay, endMonth, endYear;
    string strStartDay, strStartMonth, strStartYear;
    string strEndDay, strEndMonth, strEndYear;
    string strFromDate, strToDate;

Start:
    EnterFromDate:
    cout << "Start searching from year: ";
    startYear = AuxiliaryMethods::getIntNumber();
    cout << "and month: ";
    startMonth = AuxiliaryMethods::getIntNumber();
    cout << "and day: ";
    startDay = AuxiliaryMethods::getIntNumber();
    if(isValidDate(startDay, startMonth, startYear)) {
        cout << "Wrong date. Try again.\n";
        system("pause");
        goto EnterFromDate;
    }

    EnterToDate:
    cout << "Search to year: ";
    endYear= AuxiliaryMethods::getIntNumber();
    cout << "and month: ";
    endMonth = AuxiliaryMethods::getIntNumber();
    cout << "and day: ";
    endDay = AuxiliaryMethods::getIntNumber();
    if(isValidDate(startDay, startMonth, startYear)) {
        cout << "Wrong date. Try again.\n";
        system("pause");
        goto EnterToDate;
    }

    strStartYear = AuxiliaryMethods::convertIntToString(startYear);
    strStartMonth = AuxiliaryMethods::convertIntToString(startMonth);
    strStartDay = AuxiliaryMethods::convertIntToString(startDay);

    if (strStartMonth.length() == 1){
        strStartMonth = '0' + strStartMonth;
    }

    if (strStartDay.length() == 1){
        strStartDay = '0' + strStartDay;
    }

    strEndYear = AuxiliaryMethods::convertIntToString(endYear);
    strEndMonth = AuxiliaryMethods::convertIntToString(endMonth);
    strEndDay = AuxiliaryMethods::convertIntToString(endDay);

    if (strEndMonth.length() == 1){
        strEndMonth = '0' + strEndMonth;
    }

    if (strEndDay.length() == 1){
        strEndDay = '0' + strEndDay;
    }

    strFromDate = strStartYear + strStartMonth + strStartDay;
    strToDate = strEndYear + strEndMonth + strEndDay;

    fromDate = AuxiliaryMethods::convertStringToInt(strFromDate);
    toDate = AuxiliaryMethods::convertStringToInt(strToDate);
    if(toDate < fromDate){
        cout << "End date has to be bigger then starting date. Enter again.\n";
        system("pause");
        goto Start;
    }
}

