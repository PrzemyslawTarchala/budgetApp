#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction{
    int userId;
    string category;
    string date;
    float valueOfTransaction;

public:
    int getUserId();
    string getCategory();
    string getDate();
    float getValueOfTransaction();

    void setUserId(int newUserId);
    void setCategory(string newCategory);
    void setDate(string newDate);
    void setValueOfTransaction(float newValueOfTransaction);
};

#endif
