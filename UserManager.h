#ifndef USERMANAGER_H
#define USERMANAGER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager{
    int idLoggedUser;
    vector<User> users;
    FileWithUsers fileWithUsers;

    int getIdNewUser();

public:
    UserManager(string nameOfFileWithUsers) : fileWithUsers(nameOfFileWithUsers) {

        users = this -> fileWithUsers.loadUsersFromFile();
    };
    void userRegistration();
    void userLogIn();
    void userLogOut();
    void userChangePassword();
    bool isLogIn();

    int getIdLoggedUser();
};
#endif
