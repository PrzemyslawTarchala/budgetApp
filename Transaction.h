#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction{
    int userId;
    string category;
    int date;
    float valueOfTransaction;

public:
    int getUserId();
    string getCategory();
    int getDate();
    float getValueOfTransaction();

    void setUserId(int userId);
    void setCategory(string category);
    void setDate(int date);
    void setValueOfTransaction(float valueOfTransaction);
};

#endif
