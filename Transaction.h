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
//    Transaction(int id = 0,int idUserWhoCreatedContact = 0,string name = "",string surname = "",string email = "",string address = "",   string phone = ""){
//        this->id = id;
//        this->idUserWhoCreatedContact = idUserWhoCreatedContact;
//        this->name = name;
//        this->surname = surname;
//        this->email = email;
//        this->address = address;
//        this->phone = phone;
//    }

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
