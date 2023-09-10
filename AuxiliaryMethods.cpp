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

float AuxiliaryMethods::getFloatNumber(){
    string input;
LOOP:
    while(true){
        //cout << "Enter Income: ";
        getline(cin, input);

        if(input == ""){
            cout << "Input empty. Try again.\n";
            goto LOOP;
        }

        replace(input.begin(), input.end(), ',', '.');

        for (size_t i = 0; input.length() > i; ++i){
            if(input[i] == '.'){
                continue;
            }
            if(isdigit(input[i])){
                continue;
            }
            else{
                cout << "Incorrect input. Try again.\n";
                goto LOOP;
            }
        }
    return convertStringToFloat(input);
    }
}

float AuxiliaryMethods::convertStringToFloat(string str){
    float number;
    number = stof(str);
    return number;
}

string AuxiliaryMethods::convertFloatToString(float number){
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::getIntNumber(){
    string input = "";
    int number = 0;

    while (true)
    {
        getline(cin, input);
        stringstream myStream(input);
        if (myStream >> number)
            break;
        cout << "It's not a number. Enter again. " << endl;
    }
    return number;
}
