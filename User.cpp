#include "User.h"

void User::setId(int id){
    this -> id = id;
}

void User::setName(string name){
    this -> name = name;
}

void User::setLastname(string lastname){
    this -> lastname = lastname;
}

void User::setLogin(string login){
    this -> login = login;
}

void User::setPassword(string password){
    this -> password = password;
}

int User::getId(){
    return id;
}

string User::getName(){
    return name;
}

string User::getLastname(){
    return lastname;
}

string User::getLogin(){
    return login;
}

string User::getPassword(){
    return password;
}

