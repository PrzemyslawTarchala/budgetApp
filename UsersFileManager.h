#ifndef USERSFILEMANAGER_H
#define USERSFILEMANAGER_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "Markup.h"
#include "FileManager.h"

using namespace std;

class UsersFileManager : public FileManager{

    //CMarkup xml;
    const string ACCES_PATH_TO_USER_FILE;
    void creatUsersFileAndAddFirstUser(User userToSave);
    void openFileAndSaveNewUser(User userToSave);
    //CMarkup xml;

public:
    UsersFileManager();
    vector <User> laodUsersFromFile();
    void saveUserToFile(User userToSave);
};

#endif
