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

void TransactionsManager::showBalanceCurrentMonth(){
   sort(incomes.begin(),incomes.end(),[]( Transaction &l, Transaction &r){
         return l.getDate() < r.getDate();
        } );
    sort(expenses.begin(),expenses.end(),[]( Transaction &l, Transaction &r){
         return l.getDate() < r.getDate();
        } );

    string currentMonth = getTodayDate().substr(0,6);


    int Lp = 1;
    double sumOfIncomes = 0;
    cout<<endl<<"------INCOMES--------"<<endl;
    cout<< string("Lp.") + " Date " + " Description " + " Amount "<<endl;

    for(Transaction income : incomes){
       if(income.getDate().rfind(currentMonth,0) == 0){
            sumOfIncomes += income.getAmount();
             cout<< Lp<< ". "+ income.getDate()+" "+  " - "+income.getItem()+"    "<<income.getAmount()<<endl;
             Lp++;
        }
    }

    double sumOfExpenses = 0;
    cout<<endl<<"------EXPENSES--------"<<endl;
    cout<< string("Lp.") + " Date " + " Description " + " Amount "<<endl;
    Lp = 1;
    for(Transaction expense : expenses){
       if(expense.getDate().rfind(currentMonth,0) == 0){
            sumOfExpenses += expense.getAmount();
             cout<< Lp<< ". "+ expense.getDate()+" "+  " - "+expense.getItem()+"    "<<expense.getAmount()<<endl;
             Lp++;
        }
    }
    cout<<endl;
    cout<< "Sum of incomes equal: " <<sumOfIncomes<<endl;
    cout<< "Sum of expenses equal: " << sumOfExpenses<<endl;
    cout<< "Saldo equal: " <<(sumOfIncomes-sumOfExpenses)<<endl<<endl;

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
