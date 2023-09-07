#ifndef DATAANDTIME_H
#define DATAANDTIME_H

#include <iostream>

using namespace std;

class DataAndTime{
    int year;
    int month;
    int day;

public:
    int getYear();
    int getMonth();
    int getDay();
    void setYear(int newYear);
    void setMotnh(int newMonth);
    void setDay(int newDay);
};

#endif
