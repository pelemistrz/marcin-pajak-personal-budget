#include "UserManager.h"

using namespace std;

void UserManager::userRegistration()
{
    string login, password,name,surname;
    cout << endl;
    cout << "Please provie name: ";
    cin >>name;
    cout << endl << "Please provide your surname: ";
    cin >> surname;
    cout <<endl << "Please provide login: ";
    cin >> login;

    int i = 0;
    int sizeUser = users.size();

    while (i < sizeUser)
    {
        if (users[i].getLogin() == login)
        {
            cout << "This login exists. Please provide different." << endl;
            cin >> login;
            i = 0;
        }
        else
        {
            i++;
        }
    }

    cout << endl << "Please provide your password: ";
    cin >> password;

    User newUser;
    int userId = getIdNewUser();
    newUser.setUserId(userId);
    newUser.setLogin(login);
    newUser.setPassword(password);
    newUser.setName(name);
    newUser.setSurname(surname);

    users.push_back(newUser);
    cout << endl << "Your account has been created." << endl;

    fileWithUsers.addUserToTheFile(newUser);
}

int UserManager::getIdNewUser()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}


void UserManager::userLogIn()
{

    string login, password;
    cout << "Please provide your login: " ;
    cin >> login;

    int i = 0;
    int sizeUser = users.size();
    while (i < sizeUser)
    {
        if (users[i].getLogin() == login)
        {
            for (int attempt = 0; attempt < 3; attempt++)
            {
                cout << "Please enter your password. You have "  << 3 - attempt << " attempts:" << endl;
                cin >> password;
                if (users[i].getPassword() == password)
                {
                    cout << "You log in." << endl;
                    idLoggedUser = users[i].getUserId();
                    return;
                }
            }
            cout << " You entered 3 times wrong passwod. Try again for 3 secunds." << endl;
            Sleep(3000);
        }
        i++;
    }
    cout << "There is no user with this login." << endl;
}

void UserManager::userLogOut()
{
    idLoggedUser = 0;
}

void UserManager::userChangePassword()
{
    string newPassword = "";
    cout << "Please provide new password"<<endl;
    cin >> newPassword;

    users[idLoggedUser-1].setPassword(newPassword);
    cout << "You password has been changed"<<endl;

    fileWithUsers.changePaswordGivenUser(idLoggedUser,newPassword);

}

int UserManager::getIdLoggedUser()
{
    return idLoggedUser;
}

bool UserManager::isLogIn()
{
    bool isLogIn = false;
    if(idLoggedUser !=0 )
    {
        isLogIn = true;
    }
    return isLogIn;
}
