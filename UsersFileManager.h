#ifndef USERSFILEMANAGER_H
#define USERSFILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "FileManager.h"

using namespace std;

class UsersFileManager : public FileManager{
    const string INCOME_FILE_NAME;
    const string ACCES_PATH_TO_USER_FILE;

    void creatUsersFileAndAddFirstUser(User userToSave);
    void openFileAndSaveNewUser(User userToSave);

public:
    UsersFileManager(string userFileName) : INCOME_FILE_NAME(userFileName){
        ACCES_PATH_TO_USER_FILE = createPathToFile(INCOME_FILE_NAME);
    };

    vector <User> loadUsersFromFile();
    void saveUserToFile(User userToSave);
    void saveNewUserPasswordToFile(string newPassword, int idLoggedInUser);
};

#endif
