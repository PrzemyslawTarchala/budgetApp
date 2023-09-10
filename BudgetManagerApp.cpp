#include "BudgetManagerApp.h"

void BudgetManagerApp::signIn(){
    userManager.signIn();
    if(checkIfSomeoneIsLoggedIn()){ //stworz metode : czy uzytkownik jest zalogowany
        balanceManager = new BalanceManager(userManager.getLoggedInUserId());
    }
}

void BudgetManagerApp::signUp(){
    userManager.signUp();
}

bool BudgetManagerApp::checkIfSomeoneIsLoggedIn(){ //to przeniesc do userManger
    if(userManager.getLoggedInUserId() != 0){
        return true;
    }
    else{
        return false;
    }
}

void BudgetManagerApp::changeLoggedInUserPassword(){
    userManager.changeLoggedInUserPassword();
}

void BudgetManagerApp::logout(){
    userManager.userLogout();
    delete balanceManager;
    balanceManager = NULL;
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

//temp
void BudgetManagerApp::showUsers(){
    userManager.showUsers();
}

