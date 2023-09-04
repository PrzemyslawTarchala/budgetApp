#ifndef USERSFILEMANAGER_H
#define USERSFILEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "Markup.h"

using namespace std;

class UsersFileManager{
    const string ACCES_PATH_TO_USER_FILE = "Users.xml";
    CMarkup xml;

    string createPath();
    //void creatUserFileAndAddFirstUser();

public:
    vector <User> laodUsersFromFile();
    void saveUserToFile(User userToSave);


    void creatUserFileAndAddFirstUser();
};

#endif
