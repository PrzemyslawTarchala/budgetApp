#ifndef USERSFILEMANAGER_H
#define USERSFILEMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"
#include "Markup.h"

using namespace std;

class UsersFileManager{
    const string ACCES_PATH_TO_USER_FILE;
    CMarkup xml;

public:
    vector <User> laodUsersFromFile();
    void saveUserToFile(User userToSave);
};

#endif
