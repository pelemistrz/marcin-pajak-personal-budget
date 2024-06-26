#include <iostream>
#include "UserManager.h"

class PersonalBudget{
    UserManager userManager;

public:
    PersonalBudget(string nameOfFileWithUsers) : userManager(nameOfFileWithUsers){}
    void userRegistration();
    void userLogIn();
    void userLogOut();
    void userChangePassword();
    int getIdLoggedUser();
};
