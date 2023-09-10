#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Transaction.h"

using namespace std;

class Income : public Transaction{
    float income;

public:
    float getIncome();
    void setIncome(float newIncome);
};

#endif
