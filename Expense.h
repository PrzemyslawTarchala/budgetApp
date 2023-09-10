#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Transaction.h"

using namespace std;

class Expense : public Transaction{
    float expense;

public:
    float getExpense();
    void setExpense(int newExpense);
};

#endif
