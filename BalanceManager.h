#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>

using namespace std;

class BalanceManager{

    const int ID_LOGGEDIN_USER;

public:
    BalanceManager(int idLoggedInUser) : ID_LOGGEDIN_USER(idLoggedInUser){};

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodOfTimeBalance();
};

#endif
