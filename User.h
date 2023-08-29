#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User{
    int id;
    string name;
    string lastname;
    string login;
    string password;

public:
    void setId(int newId);
    void setName(string newName);
    void setLastname(string newLastname);
    void setLogin(string newLogin);
    void setPassword(string newPassword);

    int getId();
    string getName();
    string getLastname();
    string getLogin();
    string getPassword();
};

#endif
