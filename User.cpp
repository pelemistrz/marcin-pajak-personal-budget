#include <iostream>

#include "User.h"


void User::setUserId(int userId){
    if(this->userId >= 0)
        this->userId = userId;
}
void User::setLogin(string newLogin){
    login = newLogin;
}
void User::setPassword(string newPassword){
    password = newPassword;
}

void User::setName(string name){
    this->name = name;
}

void User::setSurname(string surname){
    this->surname = surname;
}

int User::getUserId(){
    return userId;
}
string User::getLogin(){
    return login;
}
string User::getPassword(){
    return password;
}

string User::getName(){
    return name;
}

string User::getSurname(){
    return surname;
}
