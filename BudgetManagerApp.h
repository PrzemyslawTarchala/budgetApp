#ifndef BUDGETMANAGERAPP_H
#define BUDGETMANAGERAPP_H

#include <iostream>

#include "UsersManager.h"

using namespace std;

class BudgetManagerApp{
    UserManager userManager;

public:
    void signIn();
    void singUp();
};

#endif
