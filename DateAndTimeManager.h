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
    void getTodaysDate(string &date);
    void specificDateOfTransaction(string &date);
};

#endif
