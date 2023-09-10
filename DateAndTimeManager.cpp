#include "DateAndTimeManager.h"

void DateAndTimeManager::getTodaysDate(string &date){
    string day, month, year;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    year = AuxiliaryMethods::convertIntToString(1900 + ltm-> tm_year);
    month = AuxiliaryMethods::convertIntToString(1 + ltm-> tm_mon);
    day = AuxiliaryMethods::convertIntToString(ltm -> tm_mday);

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
    string sDay, sMonth, sYear;
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

    sDay = AuxiliaryMethods::convertIntToString(day);
    sMonth = AuxiliaryMethods::convertIntToString(month);
    sYear = AuxiliaryMethods::convertIntToString(year);

    if (sMonth.length() == 1){
        sMonth = '0' + sMonth;
    }
    if (sDay.length() == 1){
        sDay = '0' + sDay;
    }
    date = sYear + sMonth + sDay;
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
        return (day <= 30);
    }
    return false;
}

bool DateAndTimeManager::isLeapYear (int year){
    if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))){
        return true;
    }
    else return false;
}
