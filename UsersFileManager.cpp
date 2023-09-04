#include "UsersFileManager.h"
#include <string>

vector <User> UsersFileManager::laodUsersFromFile(){

}

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

void UsersFileManager::creatUserFileAndAddFirstUser(){
    string path = createPath();
    xml.Save(path);
}

void UsersFileManager::saveUserToFile(User userToSave){

    ifstream file;
    file.open(ACCES_PATH_TO_USER_FILE);


    if(file){
        cout<<"file exists";
    }
    else {
        creatUserFileAndAddFirstUser();
        cout<<"file dosnt exists";
    }
    return 0;
}
