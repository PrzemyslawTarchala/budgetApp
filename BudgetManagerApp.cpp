#include "BudgetManagerApp.h"

void BudgetManagerApp::signIn(){
    userManager.signIn();
}

void BudgetManagerApp::signUp(){
    userManager.signUp();
    if(checkIfSomeoneIsLoggedIn()){ //stworz metode : czy uzytkownik jest zalogowany
        balanceManager = new BalanceManager(userManager.getLoggedInUserId());
    }
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

