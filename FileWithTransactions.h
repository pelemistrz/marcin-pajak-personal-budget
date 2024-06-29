#ifndef FILE_WITH_TRANSACTIONS_H
#define FILE_WITH_TRANSACTIONS_H

#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include "Markup.h"

#include "Transaction.h"

class FileWithTransactions{
    const string NAME_OF_THE_FILE;
    int idLastTransaction;
public:
    FileWithTransactions(string nameOfTheFile): NAME_OF_THE_FILE(nameOfTheFile){
     idLastTransaction = 0;
    }

    vector<Transaction> loadTransactionsFromFile(int idLoggedUser);
    void addTransactionToTheFile(Transaction transaction);
    int getIdLastTransaction();
};




#endif
