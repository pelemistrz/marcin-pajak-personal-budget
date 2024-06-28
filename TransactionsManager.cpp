#include "TransactionsManager.h"

void TransactionsManager::addIncome(){
    addTransaction(fileWithIncomes,"income");
}

void TransactionsManager::addExpense(){
    addTransaction(fileWithExpenses, "expense");

}
void TransactionsManager::addTransaction(FileWithTransactions whichFileToSave, string whichTransaction){
    string item;
    string date;
    string amount;
    double doubleAmount;

    cout<< "Please enter date in format \"yyyymmdd\" or press 1 to save with today date: ";
    cin>>date;
    if(date=="1"){
        date = getTodayDate();
    } else {
        date = "20011111";
    }

    cout <<"Please enter description of the " + whichTransaction +": ";
    cin.sync();
    getline(cin,item,'\n');
    cout<<endl<<"Please enter amount in format of double \"xx.xx\": ";
    cin>> amount;

    doubleAmount = stod(amount);
    cout<<endl<<doubleAmount;


    Transaction transaction;
    transaction.setTransactonId(2);
    transaction.setIdUserWhoCreatedTransaction(ID_LOGGED_USER);
    transaction.setDate(date);
    transaction.setItem(item);
    transaction.setAmount(doubleAmount);

    incomes.push_back(transaction);
    whichFileToSave.addTransactionToTheFile(transaction);

    cout<<endl<< "Your " +whichTransaction +" has been added. "<<endl ;
    system("pause");
    system("cls");
    }




string TransactionsManager::getTodayDate(){
    time_t rawtime;
    tm* timeinfo;
    char todayDate [30];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(todayDate,30,"%Y%m%d",timeinfo);
    return todayDate;
}
