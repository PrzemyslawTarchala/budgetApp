<<<<<<< HEAD
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
=======
#include <iostream>
#include <ctime>

using namespace std;

//It will be a class
struct Date{
    int year;
    int month;
    int day;
};

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
    return 0;
}
>>>>>>> origin/main
