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
                idLoggedInUser = singleUser.getId(); //do zmiany ID loggedinuser powinno byc w usersFileManager
                return;
            }
        }
        cout << "\nWrong Login or password. Left: " << i-1 << " attempts.\n\n";
    }
    cout << "Something goes wrong.\n";
    system("pause");
}

void UserManager::signUp(){
    User newUser;

    system ("cls");
    cout << "          SIGN UP\n";
    cout << "----------------------------\n\n";

    newUser = specifyNewUserData();
    users.push_back(newUser);
    userFileManager.saveUserToFile(newUser);
}

User UserManager::specifyNewUserData(){
    User newUser;

    //Nie powinno sie dac wpisac psutego imienia i nazwiska

    newUser.setId(getIdForNewUser());
    do{
        cout << "Enter name: ";
        newUser.setName(AuxiliaryMethods::getWholeLine());
        if (newUser.getName() == "") cout << "You must enter name. Enter again.\n\n";
    }while(newUser.getName() == "");

    do{
        cout << "Enter lastname: ";
        newUser.setLastname(AuxiliaryMethods::getWholeLine());
        if (newUser.getLastname() == "") cout << "You must enter Lastname. Enter again.\n\n";
    }while(newUser.getLastname() == "");

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
            cout << "\nYou must enter Login.\n";
        }
    }while(newLogin == "" || isNewLoginAvailable(newLogin));
    return newLogin;
}


bool UserManager::isNewLoginAvailable(string newLogin){

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
            cout << "\nThere is a diffrent beetwen both password. Try again.\n";
        }
    }while(newPassword != doubleCheckPassword);
    return newPassword;
}

//Tutaj zmiana hasla do roziwniecia -> mozesz sie wzorowac na funkcji powyzej
void UserManager::changeLoggedInUserPassword(){
    string newPassword;
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::getWholeLine();
    //walidacja typu --> nie moze byc pustego stringa
    //potrzebujesz zapisac to do wektora od razu
    userFileManager.saveNewUserPasswordToFile(newPassword, idLoggedInUser);
}


//temp
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
