#ifndef TRANSACTIONSMANAGER_H
#define TRANSACTIONSMANAGER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

#include "FileWithTransactions.h"
#include "Transaction.h"


using namespace std;

class TransactionsManager{
    const int ID_LOGGED_USER;
    vector<Transaction> incomes;
    vector<Transaction> expenses;
    FileWithTransactions fileWithIncomes;
    FileWithTransactions fileWithExpenses;

    string getTodayDate();
    string getPreviousMonth();

    void addTransaction(FileWithTransactions whichFileToSave, string whichKindOfTransaction);
    void showBalance(string date);
    bool checkDate(string date);
    int getNumberOfDays(int month, int year);

public:
     TransactionsManager(string nameOfFileWithIncomes,string nameOfFileWithExpenses, int idLoggedUser) : fileWithIncomes(nameOfFileWithIncomes), fileWithExpenses(nameOfFileWithExpenses) ,ID_LOGGED_USER(idLoggedUser){
         incomes = fileWithIncomes.loadTransactionsFromFile(ID_LOGGED_USER);
         expenses = fileWithExpenses.loadTransactionsFromFile(ID_LOGGED_USER);
     }

     void addIncome();
     void addExpense();
     void showBalanceCurrentMonth();
     void showBalancePreviousMonth();
};

#endif
