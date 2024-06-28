#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H


#include <fstream>
#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"


using namespace std;

class FileWithUsers{
    const string NAME_OF_FILE_WITH_USERS;

public:
    FileWithUsers(string nameOfFileWithUsers) : NAME_OF_FILE_WITH_USERS(nameOfFileWithUsers){}
    void addUserToTheFile(User user);
    vector<User> loadUsersFromFile();
    void changePaswordGivenUser(int userId, string newPassword);
};
#endif
