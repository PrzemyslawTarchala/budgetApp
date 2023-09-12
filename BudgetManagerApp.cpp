#include "BudgetManagerApp.h"

int BudgetManagerApp::getLoggedInUserId(){
    userManager.getLoggedInUserId();
}

void BudgetManagerApp::signIn(){
    userManager.signIn();
    if(userManager.isSomeoneLoggedIn()){
        balanceManager = new BalanceManager(INCOMES_FILE_NAME, EXPENSES_FILE_NAME, userManager.getLoggedInUserId());
    }
}

void BudgetManagerApp::signUp(){
    userManager.signUp();
}

void BudgetManagerApp::logout(){
    userManager.userLogout();
    delete balanceManager;
    balanceManager = NULL;
}

void BudgetManagerApp::changeLoggedInUserPassword(){
    userManager.changeLoggedInUserPassword();
}

void BudgetManagerApp::addIncome(){
    balanceManager -> addIncome();
}

void BudgetManagerApp::addExpense(){
   balanceManager -> addExpense();
}

void BudgetManagerApp::displayCurrentMonthBalance(){
    balanceManager -> displayCurrentMonthBalance();
}

void BudgetManagerApp::displayPreviousMonthBalance(){
    balanceManager -> displayPreviousMonthBalance();
}

void BudgetManagerApp::displaySpecificPeriodOfTimeBalance(){
    balanceManager -> displaySpecificPeriodOfTimeBalance();
}

void BudgetManagerApp::displayAllIncomesLoggedInUser(){
    balanceManager -> displayAllIncomesLoggedInUser();
}

void BudgetManagerApp::displayAllExpensesLoggedInUser(){
    balanceManager -> displayAllExpensesLoggedInUser();
}

//temp
void BudgetManagerApp::showUsers(){
    userManager.showUsers();
}

