#include "BudgetManagerApp.h"

void BudgetManagerApp::signIn(){
    userManager.signIn();
}

void BudgetManagerApp::signUp(){
    userManager.signUp();
}

bool BudgetManagerApp::checkIfSomeoneIsLoggedIn(){
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


//temp
void BudgetManagerApp::showUsers(){
    userManager.showUsers();
}

