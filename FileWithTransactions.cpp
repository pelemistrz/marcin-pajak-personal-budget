#include "FileWithTransactions.h"

using namespace std;

vector<Transaction> FileWithTransactions::loadTransactionsFromFile(int idLoggedUser)
{
    CMarkup xml;
    Transaction transaction;
    vector<Transaction> transactions;
    int number = 0;

    bool fileExists = xml.Load(NAME_OF_THE_FILE);
    if(fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Transaction"))
        {
            xml.IntoElem();
            xml.FindElem("IdUserWhoCreatedTransaction");
            int idUserWhoCreatedTransaction = atoi(MCD_2PCSZ(xml.GetData()));
            if(idUserWhoCreatedTransaction==idLoggedUser){
            transaction.setIdUserWhoCreatedTransaction(idUserWhoCreatedTransaction);
            xml.FindElem("TransactionId");
            int transactionId = atoi(MCD_2PCSZ(xml.GetData()));
            number = transactionId;
            transaction.setTransactonId(transactionId);



            xml.FindElem("Date");
            string date = xml.GetData();
            transaction.setDate(date);

            xml.FindElem("Item");
            string item = xml.GetData();
            transaction.setItem(item);

            xml.FindElem("Amount");
            double amount = atof(MCD_2PCSZ(xml.GetData()));
            transaction.setAmount(amount);
            transactions.push_back(transaction);
            }
            xml.OutOfElem();
        }
    }
    this->idLastTransaction = number;
    return transactions;
}


void FileWithTransactions::addTransactionToTheFile(Transaction transaction) {
    CMarkup xml;
    bool fileExists = xml.Load(NAME_OF_THE_FILE);
    string amount;

    if(!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Transactions");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Transaction");
    xml.IntoElem();
    xml.AddElem("TransactionId", transaction.getTransactionId());
    xml.AddElem("IdUserWhoCreatedTransaction", transaction.getIdUserWhoCreatedTransaction());
    xml.AddElem("Date", transaction.getDate());
    xml.AddElem("Item", transaction.getItem());
    amount = to_string(transaction.getAmount());
    xml.AddElem("Amount",amount);
    xml.Save(NAME_OF_THE_FILE);
    this->idLastTransaction += 1;
}

int FileWithTransactions::getIdLastTransaction(){
    return idLastTransaction;
}
