#include <iostream>
#include "UserManager.h"
#include "TransactionsManager.h"

class PersonalBudget{
    UserManager userManager;
    TransactionsManager *transactionsManager;
    const string NAME_OF_FILE_WITH_INCOMES;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    PersonalBudget(string nameOfFileWithUsers, string nameOfFileWithIncomes,string nameOfFileWithExpenses) : userManager(nameOfFileWithUsers),NAME_OF_FILE_WITH_INCOMES(nameOfFileWithIncomes),
    NAME_OF_FILE_WITH_EXPENSES(nameOfFileWithExpenses){
        transactionsManager = NULL;
    }
    ~PersonalBudget(){
        delete transactionsManager;
        transactionsManager = NULL;
    }

    void addIncome();
    void addExpense();
    void showBalanceCurrentMonth();

    void userRegistration();
    void userLogIn();
    void userLogOut();
    void userChangePassword();
    int getIdLoggedUser();

};
