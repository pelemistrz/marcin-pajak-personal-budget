#include "Transaction.h"

void Transaction::setTransactonId(int transactionId){
    this -> transactionId = transactionId;
}
void Transaction::setDate(string date){
    this-> date = date;
}
void Transaction::setItem(string item){
    this->item = item;
}
void Transaction::setAmount(double amount){
    this->amount = amount;
}

 void Transaction::setIdUserWhoCreatedTransaction(int idUserWhoCreatedTransaction){
    this -> idUserWhoCreatedTransaction = idUserWhoCreatedTransaction;
 }


int Transaction::getTransactionId(){
    return transactionId;
}
 int Transaction::getIdUserWhoCreatedTransaction(){
    return idUserWhoCreatedTransaction;
 }

string Transaction::getDate(){
    return date;
}
string Transaction::getItem(){
    return item;
}
double Transaction::getAmount(){
    return amount;
}
