#include <iostream>

#include "BudgetManagerApp.h"

//lib to delete
#include "UsersFileManager.h"
#include "User.h"
#include <vector>

using namespace std;

int main()
{
    BudgetManagerApp budgetAppManager;

    //budgetAppManager.singUp();

    //to delete
    User user;
    vector <User> usersTest;
    UsersFileManager usersFileManager;

    usersFileManager.creatUserFileAndAddFirstUser();
    return 0;
}
