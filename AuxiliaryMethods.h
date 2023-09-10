#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods{


public:
    static string getWholeLine();
    static char getSign();
    static float getFloatNumber();
    static string convertIntToString(int number);
    static int getIntNumber();
    static string convertFloatToString(float number);
    static float convertStringToFloat(string str);

};

#endif
