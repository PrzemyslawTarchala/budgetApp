#include "UsersFileManager.h"
#include <string>

UsersFileManager::UsersFileManager(){
    string fileName = "\\\\User.xml"; //rozwiazac przez liste inicjalizacyjna
    ACCES_PATH_TO_USER_FILE = createPathToFile(fileName);
}

vector <User> UsersFileManager::laodUsersFromFile(){

}
/*
string UsersFileManager::createPath(){

    string file_path = __FILE__;
    string dir_path = file_path.substr(0, file_path.rfind("\\"));
    string newPath;

    for (int i = 0; i < dir_path.length(); ++i){
        if(dir_path[i] == '\\'){
            newPath += "\\\\";
        }
        else{
            newPath += dir_path[i];
        }
    }
    newPath = newPath + "\\\\User.xml";
    cout << newPath;
    return newPath;
}
*/

void UsersFileManager::saveUserToFile(User userToSave){
    ifstream file;
    file.open(ACCES_PATH_TO_USER_FILE);
    if(file){
        //cout << "file exists" << endl;
        openFileAndSaveNewUser(userToSave);
    }
    else {
        //cout << "file doesnt exists" << endl;
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
