#include "FileWithTransactions.h"

using namespace std;

vector<Transaction> FileWithTransactions::loadTransactionsFromFile(int idLoggedUser)
{
    CMarkup xml;
    Transaction transaction;
    vector<Transaction> transactions;

    bool fileExists = xml.Load(NAME_OF_THE_FILE);
    if(fileExists)
    {
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("Transaction"))
        {
            xml.IntoElem();
            xml.FindElem("TransactionId");
            int transactionId = atoi(MCD_2PCSZ(xml.GetData()));
            transaction.setTransactonId(transactionId);
            xml.FindElem("IdUserWhoCreatedTransaction");
            int idUserWhoCreatedTransaction = atoi(MCD_2PCSZ(xml.GetData()));
            transaction.setIdUserWhoCreatedTransaction(idUserWhoCreatedTransaction);
            xml.FindElem("Date");
            string date = xml.GetData();
            transaction.setDate(date);
            xml.FindElem("Item");
            string item = xml.GetData();
            transaction.setItem(item);
            xml.FindElem("Amount");
            //sprawdzic jak sie wyciaga double z cmarkup
            double amount = stod(MCD_2PCSZ(xml.GetData()));
            transaction.setAmount(amount);
            transactions.push_back(transaction);
            xml.OutOfElem();
        }
    }
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
}
