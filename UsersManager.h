#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "UsersFileManager.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersManager{

    int idLoggedInUser;
    vector <User> users;
    UsersFileManager userFileManager;

    User specifyNewUserData();
    int getIdForNewUser();
    bool isNewLoginAvailable(string newLogin);
    string enterTwiceSamePassword();
    string enterNewLogin();

public:

    UsersManager(string userFileName) : userFileManager(userFileName){
        users = userFileManager.loadUsersFromFile();
        idLoggedInUser = 0;
    };
    int getLoggedInUserId();

    void signIn();
    void signUp();
    void userLogout();
    void changeLoggedInUserPassword();
    bool isSomeoneLoggedIn();

    //temp
    //void showUsers();
};

#endif
