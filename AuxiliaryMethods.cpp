#include "AuxiliaryMethods.h"

string AuxiliaryMethods::getWholeLine(){
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::getSign(){
    string input = "";
    char sign  = {0};
    while (true)
    {
        getline(cin, input);
        if (input.length() == 1)
        {
            sign = input[0];
            break;
        }
        cout << "\nIt isn't sign! Enter again: ";
    }
    return sign;
}
