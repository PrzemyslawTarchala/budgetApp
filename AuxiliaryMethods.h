#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods{

public:
    static char getSign();
    static int getIntNumber();
    static string getWholeLine();
    static float getFloatNumber();
    static int convertStringToInt(string str);
    static string convertIntToString(int number);
    static string convertFloatToString(float number);
    static float convertStringToFloat(string str);

};

#endif
