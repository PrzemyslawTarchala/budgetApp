#ifndef BUDGETMANAGERAPP_H
#define BUDGETMANAGERAPP_H

#include <iostream>

#include "UsersManager.h"

using namespace std;

class BudgetManagerApp{
    UserManager userManager;

public:

    void signIn();
    void signUp();
    bool checkIfSomeoneIsLoggedIn();
    void changeLoggedInUserPassword();


    //temp
    void showUsers();
};

#endif
