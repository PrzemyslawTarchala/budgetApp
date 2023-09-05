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
    UsersFileManager usersFileManager;

    //budgetAppManager.singUp();
    budgetAppManager.signIn ();
    budgetAppManager.changeLoggedInUserPassword();
    //budgetAppManager.showUsers();
    //to delete
    //User user;
    //vector <User> usersTest;
    //UsersFileManager usersFileManager;


    return 0;
}
