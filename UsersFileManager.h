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

    const string ACCES_PATH_TO_USER_FILE;
    void creatUsersFileAndAddFirstUser(User userToSave);
    void openFileAndSaveNewUser(User userToSave);

public:
    UsersFileManager();

    vector <User> laodUsersFromFile();
    void saveUserToFile(User userToSave);
};

#endif
