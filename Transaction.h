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

    void setUserId(int newUserId);
    void setCategory(string newCategory);
    void setDate(int newDate);
    void setValueOfTransaction(float newValueOfTransaction);
};

#endif
