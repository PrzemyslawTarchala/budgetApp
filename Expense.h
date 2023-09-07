#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "DataAndTime.h"

using namespace std;

class Expense : public DataAndTime{

    int userId;
    float income;
    string category;

public:
    int getUserId();
    float getIncome();
    string getCategory();
    void setUserId(int newUserId);
    void setIncome(int newIncome);
    void setCategory(int newCategory);
};

#endif
