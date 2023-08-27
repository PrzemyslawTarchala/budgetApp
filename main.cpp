#include <iostream>
#include <ctime>

using namespace std;


struct Date{
    int year;
    int month;
    int day;
};

/*
bool isSmallerOrSameDate(Date smallerDate, Date compareDate){

    if(smallerDate.year > compareDate.year){
        return false;
    }
    else{
        if(smallerDate.month > compareDate.month && smallerDate.month != compareDate.month){
            return false;
        }
        else{
            if(smallerDate.day >= compareDate.day){
                return false;
            }
        }
    }
    return true;
}


bool isSmallerOrSameDate(Date smallerDate, Date compareDate){

    if(isBiggerNumebr(smallerDate.year, compareDate.year)){
        return false;
    }
    if(isBiggerNumebr(smallerDate.month, compareDate.month)){
        return false;
    }
    if(isBiggerNumebr(smallerDate.day, compareDate.day)){
        return false;
    }
}
*/


bool isSmallerOrSameDate(Date smallerDate, Date compareDate){
    if(smallerDate.year > compareDate.year){
        return false;
    }
    else if(smallerDate.year < compareDate.year){
        return true;
    }
    else{
        if(smallerDate.month > compareDate.month){
            return false;
        }
        else if(smallerDate.month < compareDate.month){
            return true;
        }
        else{
            if (smallerDate.day > compareDate.day){
                return false;
            }
            else{
                return true;
            }
        }
    }
}

Date getCurrentDate(){
    Date currentDate;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    currentDate.year = 1900 + ltm-> tm_year;
    currentDate.month = 1 + ltm-> tm_mon;
    currentDate.day = ltm -> tm_mday;

    return currentDate;
}

bool isLeapYear (int year){
    if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0))){
        return true;
    }
    else return false;
}

bool isValidDate(int day, int month, int year){

    if (month < 1 || month > 12){
        return false;
    }
    if (day < 1 || day > 31){
        return false;
    }


    if (month == 2){
        if (isLeapYear(year)){
            if (day > 29){
                 return false;
            }
        }
        else{
            if (day > 28){
                return false;
            }
        }
    }

    if (month == 4 || month == 6 || month == 9 || month == 11){
        return (day <= 30);
    }
    return true;
}


int main()
{
    Date dataOne, dataTwo;

    dataOne.year = 2002;
    dataOne.month = 11;
    dataOne.day = 2;

    dataTwo.year = 2002;
    dataTwo.month = 10;
    dataTwo.day = 2;

    if (isSmallerOrSameDate(dataOne, dataTwo)){
        cout << "Data pierwsza jest mniejsza lub taka sama od daty 2" << endl;
    }
    else {
        cout << "Data pierwsza jest wieksza od daty 2" << endl;
    }
    return 0;
}
