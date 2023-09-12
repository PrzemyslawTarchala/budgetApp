#ifndef DATEANDTIMEMANAGER_H
#define DATEANDTIMEMANAGER_H

#include <iostream>
#include <ctime>

#include "AuxiliaryMethods.h"

using namespace std;

class DateAndTimeManager{

    bool isValidDate(int day, int month, int year);
    bool isLeapYear (int year);

public:
    int getYear();
    int getMonth();
    int getDay();
    int getNumbersOfDays(int month, int year);
    void getTodaysDate(string &date);
    void specificDateOfTransaction(string &date);
    void getTimeFrameForCurrentMonth(int &fromDate, int &toDate);
    void getTimeFrameForPrevoiusMonth(int &fromDate, int &toDate);
    void getTimeFrameSpecificByUser(int &fromDate, int &toDate);
};

#endif
