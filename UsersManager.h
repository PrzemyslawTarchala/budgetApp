#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UsersFileManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager{

    int idLoggedInUser;
    vector <User> users;
    UsersFileManager userFileManager;

    User specifyNewUserData();
    int getIdForNewUser();
    bool isNewLoginAvailable(string newLogin);
    string enterTwiceSamePassword();
    string enterNewLogin();

public:

    UserManager();
    int getLoggedInUserId();

    void signIn();
    void signUp();
    void changeLoggedInUserPassword();

    //temp
    void showUsers();
};

#endif
