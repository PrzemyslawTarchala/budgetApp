#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction{
    int userId;
    string category;
    string date;

public:
    int getUserId();
    string getCategory();
    string getDate();
    void setUserId(int newUserId);
    void setCategory(string newCategory);
    void setDate(string newDate);
};

#endif
