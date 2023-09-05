#include "BudgetManagerApp.h"

void BudgetManagerApp::signIn(){
    userManager.signIn();
}

void BudgetManagerApp::singUp(){
    userManager.signUp();
}

void BudgetManagerApp::changeLoggedInUserPassword(){
    userManager.changeLoggedInUserPassword();
}

void BudgetManagerApp::showUsers(){
    userManager.showUsers();
}
