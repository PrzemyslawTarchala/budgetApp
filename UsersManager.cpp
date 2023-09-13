#include "UsersManager.h"

int UsersManager::getLoggedInUserId(){
    return idLoggedInUser;
}

void UsersManager::signIn(){
    string login, password;
    int loginAttempt = 3;

    system ("cls");
    cout << "          SIGN IN\n";
    cout << "----------------------------\n\n";

    if (users.empty()){
        cout << "There is no users. Must sing up first.\n\n";
        system ("pause");
        return;
    }

    for (int i = loginAttempt; i > 0; --i){
        cout << "Enter login: ";
        login = AuxiliaryMethods::getWholeLine();
        cout << "Enter password: ";
        password = AuxiliaryMethods::getWholeLine();

        for (User singleUser : users){
            if(singleUser.getLogin() == login && singleUser.getPassword() == password){
                idLoggedInUser = singleUser.getId();
                return;
            }
        }
        cout << "\nWrong Login or password. Left: " << i-1 << " attempts.\n\n";
    }
    system("pause");
}

void UsersManager::signUp(){
    User newUser;

    system ("cls");
    cout << "          SIGN UP\n";
    cout << "----------------------------\n\n";

    newUser = specifyNewUserData();
    users.push_back(newUser);
    userFileManager.saveUserToFile(newUser);
    cout << "\nAccount created.\n\n";
    system("pause");
}

void UsersManager::userLogout(){
    system ("cls");
    cout << "          LOGGED OUT\n";
    cout << "----------------------------\n\n";
    idLoggedInUser = 0;
    system("pause");
}

User UsersManager::specifyNewUserData(){

    User newUser;
    newUser.setId(getIdForNewUser());
    do{
        cout << "Enter name: ";
        newUser.setName(AuxiliaryMethods::getWholeLine());
        if (newUser.getName() == "") cout << "You must enter name. Enter again.\n\n";
    }while(newUser.getName() == "");

    do{
        cout << "Enter last name: ";
        newUser.setLastname(AuxiliaryMethods::getWholeLine());
        if (newUser.getLastname() == "") cout << "You must enter last name. Enter again.\n\n";
    }while(newUser.getLastname() == "");

    newUser.setLogin(enterNewLogin());
    newUser.setPassword(enterTwiceSamePassword());
    return newUser;
}

int UsersManager::getIdForNewUser(){

    if (users.empty()){
        return 1;
    }
    else{
        return users.back().getId() + 1;
    }
}

string UsersManager::enterNewLogin(){

    string newLogin;
    do{
        cout << "Enter Login: ";
        newLogin = AuxiliaryMethods::getWholeLine();

        if (newLogin == ""){
            cout << "\nYou must enter Login.\n";
        }
    }while(newLogin == "" || isNewLoginAvailable(newLogin));
    return newLogin;
}


bool UsersManager::isNewLoginAvailable(string newLogin){

    if(users.size() == 0){
        return false;
    }
    else{
        for (User singleUser : users){
            if(singleUser.getLogin() == newLogin){
                cout << "\nLogin already exist. Try again.\n";
                return true;
            }
        }
        return false;
    }
}

string UsersManager::enterTwiceSamePassword(){

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
            cout << "\nThere is a difference between both password. Try again.\n";
        }
    }while(newPassword != doubleCheckPassword);
    return newPassword;
}

void UsersManager::changeLoggedInUserPassword(){
    string newPassword;

    system ("cls");
    cout << "         NEW PASSWORD\n";
    cout << "----------------------------\n\n";
    newPassword = enterTwiceSamePassword();
    for (User &singleUser : users){
        if(singleUser.getId() == idLoggedInUser){
            singleUser.setPassword(newPassword);
        }
    }
    userFileManager.saveNewUserPasswordToFile(newPassword, idLoggedInUser);
    cout << "\nPassword changed.\n\n";
    system("pause");
}

bool UsersManager::isSomeoneLoggedIn(){
    if(idLoggedInUser != 0){
        return true;
    }
    else{
        return false;
    }
}


//temp
/*
void UsersManager::showUsers(){
    if(users.empty()){
        cout << "Empty vector ";
    }
    else{
        for (User singleUser : users){
            cout << singleUser.getId() << endl;
            cout << singleUser.getPassword() << endl;
        }
    }
    system("pause");
}*/
