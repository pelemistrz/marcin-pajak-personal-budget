#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

using namespace std;

class Transaction{
    int transactionId;
    int idUserWhoCreatedTransaction;
    string date;
    string item;
    double amount;



public:
    Transaction(int transactionId = 0,int idUserWhoCreatedTransaction = 0,string date = "",string item = "",   double amount = 0.0){
        this->transactionId = transactionId;
        this->idUserWhoCreatedTransaction = idUserWhoCreatedTransaction;
        this->date = date;
        this->item = item;
        this->amount = 0.0;
        }

    void setTransactonId(int transactionId);
    void setIdUserWhoCreatedTransaction(int idUserWhoCreatedTransaction);
    void setDate(string date);
    void setItem(string item);
    void setAmount(double amount);


    int getTransactionId();
    int getIdUserWhoCreatedTransaction();
    string getDate();
    string getItem();
    double getAmount();

};

#endif // USER_H
