#include "UsersManager.h"

UserManager::UserManager(){
    users = userFileManager.loadUsersFromFile();
    idLoggedInUser = 0;
}

int UserManager::getLoggedInUserId(){
    return idLoggedInUser;
}

void UserManager::signIn(){
    string login, password;

    cout << "Enter login: ";
    login = AuxiliaryMethods::getWholeLine();
    cout << "Enter password: ";
    password = AuxiliaryMethods::getWholeLine();

    for (User singleUser : users){
        if(singleUser.getLogin() == login && singleUser.getPassword() == password){
            cout << "Logged";
            idLoggedInUser = singleUser.getId(); //do zmiany ID loggedinuser powinno byc w usersFileManager
            return;
        }
    }
    cout << "Wrong Login or password";
}

void UserManager::signUp(){
    User newUser;
    newUser = specifyNewUserData();
    userFileManager.saveUserToFile(newUser);
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

    if (users.empty()){
        return 1;
    }
    else{
        return users.back().getId() + 1;
    }
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
    string newPassword;
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::getWholeLine();
    //walidacja typu --> nie moze byc pustego stringa
    //potrzebujesz zapisac to do wektora od razu
    userFileManager.saveNewUserPasswordToFile(newPassword, idLoggedInUser);
}

void UserManager::showUsers(){

    if(users.empty()){
        cout << "Pusto ";
    }
    else{
        for (User singleUser : users){
            cout << singleUser.getId() << endl;
        }
    }
}
