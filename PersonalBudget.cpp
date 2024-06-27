#include "PersonalBudget.h"


void PersonalBudget::userRegistration(){
    userManager.userRegistration();
}

void PersonalBudget::userLogIn(){
      userManager.userLogIn();
//      if(userManager.isLogIn()){
//        contactManager = new ContactManager(NAME_OF_FILE_WITH_CONTACTS, userManager.getIdLoggedUser());
//      }

}

void PersonalBudget::userLogOut(){
    userManager.userLogOut();
//    delete contactManager;
//    contactManager = NULL;
}

void PersonalBudget::userChangePassword(){
//    userManager.userChangePassword();
}
int PersonalBudget::getIdLoggedUser(){
    return userManager.getIdLoggedUser();
}
