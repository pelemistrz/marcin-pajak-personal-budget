#include "PersonalBudget.h"


void PersonalBudget::userRegistration(){
    userManager.userRegistration();
}

void PersonalBudget::userLogIn(){
      userManager.userLogIn();
      if(userManager.isLogIn()){
        transactionsManager = new TransactionsManager(NAME_OF_FILE_WITH_INCOMES,NAME_OF_FILE_WITH_EXPENSES, userManager.getIdLoggedUser());
     }

}

void PersonalBudget::userLogOut(){
    userManager.userLogOut();
    delete transactionsManager;
    transactionsManager = NULL;
}

void PersonalBudget::userChangePassword(){
//    userManager.userChangePassword();
}
int PersonalBudget::getIdLoggedUser(){
    return userManager.getIdLoggedUser();
}

void PersonalBudget::addIncome(){
    transactionsManager->addIncome();
}

void PersonalBudget::addExpense(){
    transactionsManager->addExpense();
}
