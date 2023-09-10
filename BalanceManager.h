#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include "Income.h"
#include "Expense.h"
#include "IncomeFileManager.h"
#include "ExpenseFileManager.h"
#include "DateAndTimeManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BalanceManager{

    const int ID_LOGGEDIN_USER;
    DateAndTimeManager dateAndTimeManager;
    IncomeFileManager incomeFileManager;
    ExpenseFileManager expenseFileManager;

    Income specifyNewIncome();
    string getDate();

public:
    BalanceManager(int idLoggedInUser) : ID_LOGGEDIN_USER(idLoggedInUser){};

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodOfTimeBalance();
};

#endif

