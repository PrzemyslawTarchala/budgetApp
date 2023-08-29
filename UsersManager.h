#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UsersFileManager.h"

using namespace std;

class UserManager{

    int idLoggedInUser;
    vector <User> users;
    UsersFileManager userFileManager;

    User specifyNewUserData();
    int getIfForNewUser();
    bool isNewLoginAvailable();
    string eneterTwiceSamePassword();

public:

    UserManger();
    int getLoggedInUserId();

    void signIn();
    void signOut();
    void changeLoggedInUserPassword();
};

#endif
