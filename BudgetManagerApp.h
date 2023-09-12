#ifndef BUDGETMANAGERAPP_H
#define BUDGETMANAGERAPP_H

#include <iostream>

#include "UsersManager.h"
#include "BalanceManager.h"

using namespace std;

class BudgetManagerApp{
    UserManager userManager;
    BalanceManager *balanceManager;

    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    BudgetManagerApp(string usersFileName, string incomeFileName, string expenseFileName)
        : userManager(usersFileName), INCOMES_FILE_NAME(incomeFileName), EXPENSES_FILE_NAME(expenseFileName){
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
    void logout();

    void addIncome();
    void addExpense();
    void displayCurrentMonthBalance();
    void displayPreviousMonthBalance();
    void displaySpecificPeriodOfTimeBalance();

        //temp
    void showUsers();
    void displayAllIncomesLoggedInUser();
    void displayAllExpensesLoggedInUser();
};

#endif
