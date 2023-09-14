#include "UsersFileManager.h"

vector <User> UsersFileManager::loadUsersFromFile(){

    CMarkup xml;
    User userFromFile;
    vector <User> usersFromFile;

    ifstream userFile;
    userFile.open(ACCES_PATH_TO_USER_FILE);
    if(userFile.good()){
        xml.Load(ACCES_PATH_TO_USER_FILE);
        xml.FindElem();
        xml.IntoElem();

        while(xml.FindElem("User")){
            xml.IntoElem();
            xml.FindElem("ID");
            userFromFile.setId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("Name");
            userFromFile.setName(xml.GetData());
            xml.FindElem("Lastname");
            userFromFile.setLastname(xml.GetData());
            xml.FindElem("Login");
            userFromFile.setLogin(xml.GetData());
            xml.FindElem("Password");
            userFromFile.setPassword(xml.GetData());
            xml.OutOfElem();
            usersFromFile.push_back(userFromFile);
        }
    }
    else{
        cout << "User File failed to open." << endl;
    }

    return usersFromFile;
}

void UsersFileManager::saveUserToFile(User userToSave){
    ifstream file;
    file.open(ACCES_PATH_TO_USER_FILE);
    if(file){
        openFileAndSaveNewUser(userToSave);
    }
    else {
        creatUsersFileAndAddFirstUser(userToSave);
    }
}

void UsersFileManager::creatUsersFileAndAddFirstUser(User userToSave){

    CMarkup xml;
    xml.AddElem("UserList");
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("ID", userToSave.getId());
    xml.AddElem("Name", userToSave.getName());
    xml.AddElem("Lastname", userToSave.getLastname());
    xml.AddElem("Login", userToSave.getLogin());
    xml.AddElem("Password", userToSave.getPassword());
    xml.Save(ACCES_PATH_TO_USER_FILE);
    xml.ResetMainPos();
}

void UsersFileManager::openFileAndSaveNewUser(User userToSave){

    CMarkup xml;
    xml.Load(ACCES_PATH_TO_USER_FILE);

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("ID", userToSave.getId());
    xml.AddElem("Name", userToSave.getName());
    xml.AddElem("Lastname", userToSave.getLastname());
    xml.AddElem("Login", userToSave.getLogin());
    xml.AddElem("Password", userToSave.getPassword());
    xml.Save(ACCES_PATH_TO_USER_FILE);
    xml.ResetMainPos();
}

void UsersFileManager::saveNewUserPasswordToFile(string newPassword, int idLoggedInUser){

    CMarkup xml;
    xml.Load(ACCES_PATH_TO_USER_FILE);
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User")){
        xml.IntoElem();
        xml.FindElem("ID");
        if (atoi(MCD_2PCSZ(xml.GetData())) == idLoggedInUser){
            xml.FindElem("Password");
            xml.SetData(newPassword);
            xml.Save(ACCES_PATH_TO_USER_FILE);
        }
        xml.OutOfElem();
    }
}
