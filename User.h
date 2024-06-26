#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User{
    int userId;
    string login;
    string password;
    string name;
    string surname;
public:
    void setUserId(int userId);
    void setLogin(string newLogin);
    void setPassword(string newPassword);
    void setName(string name);
    void setSurname(string surname);

    int getUserId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif // USER_H
