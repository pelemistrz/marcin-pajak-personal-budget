#include "UserManager.h"

using namespace std;

void UserManager::userRegistration(){
//    string login, password;
//    cout << endl;
//    cout << "Please provide login." << endl;
//    cin >> login;
//
//    int i = 0;
//    int sizeUser = users.size();
//    while (i < sizeUser)
//    {
//        if (users[i].getLogin() == login)
//        {
//            cout << "This login exists. Please provide different." << endl;
//            cin >> login;
//            i = 0;
//        }
//        else
//        {
//            i++;
//        }
//    }
//
//    cout << "Please provide your password." << endl;
//    cin >> password;
//
//    User newUser;
//    int userId = getIdNewUser();
//    newUser.setId(userId);
//    newUser.setLogin(login);
//    newUser.setPassword(password);
//
//    users.push_back(newUser);
//    cout << "Your account has been created." << endl;
//
//    fileWithUsers.addUserToTheFile(newUser);
}

int UserManager::getIdNewUser(){
//    if (users.empty() == true)
//        return 1;
//    else
//        return users.back().getId() + 1;
}


void UserManager::userLogIn(){

//    string login, password;
//    cout << "Please provide your login" << endl;
//    cin >> login;
//
//    int i = 0;
//    int sizeUser = users.size();
//    while (i < sizeUser)
//    {
//        if (users[i].getLogin() == login)
//        {
//            for (int attempt = 0; attempt < 3; attempt++)
//            {
//                cout << "Please enter your password. You have "  << 3 - attempt << " attempts:" << endl;
//                cin >> password;
//                if (users[i].getPassword() == password)
//                {
//                    cout << "You log in." << endl;
//                    idLoggedUser = users[i].getId();
//                    return;
//                }
//            }
//            cout << " You entered 3 times wrong passwod. Try again for 3 secunds." << endl;
//            Sleep(3000);
//        }
//        i++;
//    }
//    cout << "There is no user with this login." << endl;
}

void UserManager::userLogOut(){
//    idLoggedUser = 0;
}

void UserManager::userChangePassword(){
//    string newPassword = "";
//    cout << "Please provide new password"<<endl;
//    cin >> newPassword;
//
//    users[idLoggedUser-1].setPassword(newPassword);
//    cout << "You password has been changed"<<endl;
//
//    fileWithUsers.saveAllUsersToTheFile(users);

}

int UserManager::getIdLoggedUser(){
    return idLoggedUser;
}

bool UserManager::isLogIn(){
    bool isLogIn = false;
    if(idLoggedUser !=0 ){
        isLogIn = true;
    }
    return isLogIn;
}
