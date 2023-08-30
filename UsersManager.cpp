#include "UsersManager.h"

//UserManager::UserManager()

int UserManager::getLoggedInUserId(){
    return idLoggedInUser;
}

void UserManager::signIn(){

}

void UserManager::signUp(){
    User newUser;
    newUser = specifyNewUserData();
    userFileManager.saveUserToFile(newUser);


/*
    cout << "----NEW USER----\n\n";
    cout << newUser.getId() << endl;
    cout << newUser.getName() << endl;
    cout << newUser.getLastname() << endl;
    cout << newUser.getLogin() << endl;
    cout << newUser.getPassword() << endl;
*/
}

User UserManager::specifyNewUserData(){
    User newUser;

    //Nie powinno sie dac wpisac psutego imienia i nazwiska

    newUser.setId(getIdForNewUser());
    cout << "Enter name: ";
    newUser.setName(AuxiliaryMethods::getWholeLine());
    cout << "Enter lastname: ";
    newUser.setLastname(AuxiliaryMethods::getWholeLine());
    newUser.setLogin(enterNewLogin());
    newUser.setPassword(enterTwiceSamePassword());
    return newUser;
}

int UserManager::getIdForNewUser(){
    return 1;
}

string UserManager::enterNewLogin(){

    string newLogin;
    do{
        cout << "Enter Login: ";
        newLogin = AuxiliaryMethods::getWholeLine();
        if (newLogin == ""){
            cout << "You must enter Login.\n";
            continue;
        }
    }while(isNewLoginAvailable(newLogin));
    return newLogin;
}


bool UserManager::isNewLoginAvailable(string newLogin){
    //trzeba otworzyc plik i sprawdzic czy dziala

    if(users.size() == 0){
        return false;
    }
}

string UserManager::enterTwiceSamePassword(){

    string newPassword, doubleCheckPassword;

    do{
        cout << "Enter password: ";
        newPassword = AuxiliaryMethods::getWholeLine();

        if (newPassword == ""){
            cout << "You must enter password: ";
            continue;
        }
        cout << "Enter same password again: ";
        doubleCheckPassword = AuxiliaryMethods::getWholeLine();

        if (newPassword != doubleCheckPassword){
            cout << "There is a diffrent beetwen both password. Try again.\n";
        }
    }while(newPassword != doubleCheckPassword);
    return newPassword;
}

void UserManager::changeLoggedInUserPassword(){

}
