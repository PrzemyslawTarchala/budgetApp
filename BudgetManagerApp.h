#ifndef BUDGETMANAGERAPP_H
#define BUDGETMANAGERAPP_H

#include <iostream>

#include "UsersManager.h"
#include "BalanceManager.h"

using namespace std;

class BudgetManagerApp{
    UserManager userManager;
    BalanceManager *balanceManager;

public:
    BudgetManagerApp(){
        balanceManager = NULL;
    }
    ~BudgetManagerApp(){
        delete balanceManager;
        balanceManager = NULL;
    }

    void signIn();
    void signUp();
    bool checkIfSomeoneIsLoggedIn();

    void changeLoggedInUserPassword();

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodOfTimeBalance();

        //temp
    void showUsers();
};

#endif
