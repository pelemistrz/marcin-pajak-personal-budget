#include "FileWithUsers.h"

void FileWithUsers::addUserToTheFile(User user){
    CMarkup xml;
    bool fileExists = xml.Load(NAME_OF_FILE_WITH_USERS);

    if(!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname",user.getSurname());
    xml.Save(NAME_OF_FILE_WITH_USERS);
}

vector<User> FileWithUsers::loadUsersFromFile(){
    CMarkup xml;
    User user;
    vector<User> users;

    bool fileExists = xml.Load(NAME_OF_FILE_WITH_USERS);
    if(fileExists){
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")){
            xml.IntoElem();
            xml.FindElem("UserId");
            int userId = atoi(MCD_2PCSZ(xml.GetData()));
            cout <<userId;
            user.setUserId(userId);
            xml.FindElem("Login");
            string login = xml.GetData();
            cout <<login;
            user.setLogin(login);
            xml.FindElem("Password");
            string password = xml.GetData();
            user.setPassword(password);
            xml.FindElem("Name");
            string name = xml.GetData();
            user.setName(name);
            xml.FindElem("Surname");
            string surname = xml.GetData();
            user.setSurname(surname);
            users.push_back(user);
            xml.OutOfElem();

        }

    }

    cout <<users[0].getName();
    return users;

}

void FileWithUsers::saveAllUsersToTheFile(vector<User> &users){


}
