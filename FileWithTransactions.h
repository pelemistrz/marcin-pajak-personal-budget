#ifndef FILE_WITH_TRANSACTIONS_H
#define FILE_WITH_TRANSACTIONS_H

#include <vector>
#include "Markup.h"

#include "Transaction.h"

class FileWithTransactions{
    const string NAME_OF_THE_FILE;
public:
    FileWithTransactions(string nameOfTheFile): NAME_OF_THE_FILE(nameOfTheFile){}

    vector<Transaction> loadTransactionsFromFile(int idLoggedUser);
    void addTransactionToTheFile(Transaction transaction);
};




#endif
