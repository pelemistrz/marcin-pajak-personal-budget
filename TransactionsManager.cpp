#include "TransactionsManager.h"

void TransactionsManager::addIncome(){
    addTransaction(fileWithIncomes,"income");
}

void TransactionsManager::addExpense(){
    addTransaction(fileWithExpenses, "expense");
}

void TransactionsManager::addTransaction(FileWithTransactions whichFileToSave, string whichKindOfTransaction){
    string item;
    string inputDate;
    string date;
    char choice;
    string amount;
    double doubleAmount = 0;
    int idTransaction = 0;

    cout<< "Do you want add income with today date (enter 1) or different (enter 2): ";
    cin>>choice;

    switch(choice){
        case '1':
         date = getTodayDate();
         break;
        case '2':
          cout<<"Please enter date in format \"yyyy-mm-dd\": ";
          cin >>inputDate;
          if(checkDate(inputDate))
          {
            date = inputDate;
          } else {
              cout<<endl<<"Please try again"<<endl;
              return;
          }
          break;
        default:
            cout<<"Please choose 1 or 2"<<endl;
            return;
            break;
    }


    cout <<"Please enter description of the " + whichKindOfTransaction +": ";
    cin.sync();
    getline(cin,item,'\n');
    cout<<endl<<"Please enter amount in format of double \"xx.xx\": ";
    cin>> amount;
    doubleAmount = stod(amount);
    cout<<endl<<doubleAmount;

    idTransaction = whichFileToSave.getIdLastTransaction()+1;
    Transaction transaction;
    transaction.setTransactonId(idTransaction);
    transaction.setIdUserWhoCreatedTransaction(ID_LOGGED_USER);
    transaction.setDate(date);
    transaction.setItem(item);
    transaction.setAmount(doubleAmount);

    if(whichKindOfTransaction=="income"){
        incomes.push_back(transaction);
    } else {
        expenses.push_back(transaction);
    }
    whichFileToSave.addTransactionToTheFile(transaction);

    cout<<endl<< "Your " +whichKindOfTransaction +" has been added. "<<endl ;
    system("pause");
    system("cls");
    }


void TransactionsManager::showBalanceCurrentMonth(){
     string currentMonth =  getTodayDate().substr(0,7);
     showBalance(currentMonth);
}

void TransactionsManager::showBalancePreviousMonth(){
    string previousMonth = getPreviousMonth();
    showBalance(previousMonth);
}

void TransactionsManager::showBalance(string givenMonth){
   sort(incomes.begin(),incomes.end(),[]( Transaction &l, Transaction &r){
         return l.getDate() < r.getDate();
        } );
    sort(expenses.begin(),expenses.end(),[]( Transaction &l, Transaction &r){
         return l.getDate() < r.getDate();
        } );

    int Lp = 1;
    double sumOfIncomes = 0;
    cout<<endl<<"------INCOMES--------"<<endl;
    cout << setw(5)<<left<<"Lp."<<setw(12)<<left<< "Date"<<setw(20)<<left<<"Description"<<setw(8)<<left<<"Amount"<<endl;

    for(Transaction income : incomes){
       if(income.getDate().rfind(givenMonth,0) == 0){
            sumOfIncomes += income.getAmount();
            cout<<setw(5)<<left<< Lp<<setw(12)<<left<< income.getDate()<<setw(20)<<left<<income.getItem()<<setw(8)<<left<<income.getAmount()<<endl;
             Lp++;
        }
    }

    double sumOfExpenses = 0;
    cout<<endl<<"------EXPENSES--------"<<endl;
     cout << setw(5)<<left<<"Lp."<<setw(12)<<left<< "Date"<<setw(20)<<left<<"Description"<<setw(8)<<left<<"Amount"<<endl;
    Lp = 1;
    for(Transaction expense : expenses){
       if(expense.getDate().rfind(givenMonth,0) == 0){
            sumOfExpenses += expense.getAmount();
            cout<<setw(5)<<left<< Lp<<setw(12)<<left<< expense.getDate()<<setw(20)<<left<<expense.getItem()<<setw(8)<<left<<expense.getAmount()<<endl;
            Lp++;
        }
    }
    cout<<endl<<"--------------------------------"<<endl;
    cout<< setw(37)<<left<<"Sum of incomes: " <<sumOfIncomes<<endl;
    cout<< setw(37)<<left<< "Sum of expenses: " << sumOfExpenses<<endl;
    cout<<"-----------------------------"<<endl;
    cout<< setw(37)<<left<<"Saldo equal: " <<(sumOfIncomes-sumOfExpenses)<<endl<<endl;

    system("pause");
    system("cls");
}

string TransactionsManager::getTodayDate(){
    time_t rawtime;
    tm* timeinfo;
    char todayDate [30];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(todayDate,30,"%Y-%m-%d",timeinfo);
    return todayDate;
}

string TransactionsManager::getPreviousMonth(){
    string todayDate = getTodayDate();
    string previousMonth = "";
    int year = stoi(todayDate.substr(0,4));
    int month = stoi(todayDate.substr(5,2));
    if(month == 1){
        previousMonth = to_string(year-1)+"-"+"12";
        return previousMonth;
    } else if(month > 1 && month <11){
        previousMonth = to_string(year)+"-"+"0"+to_string(month-1);
        return previousMonth;
    } else {
        previousMonth = to_string(year)+"-"+to_string(month-1);
        return previousMonth;
    }
}


bool TransactionsManager::checkDate(string inputDate){
    int lengthOfString = inputDate.length();
    if(lengthOfString !=10){
        cout<<endl<<"The given date is wrong length"<<endl;
        return false;
    }

    int year = stoi(inputDate.substr(0,4));
    int month = stoi(inputDate.substr(5,2));
    int day = stoi(inputDate.substr(8,2));

    int currentYear = stoi(getTodayDate().substr(0,4));
    int currentMonth = stoi(getTodayDate().substr(5,2));
    int currentDay = stoi(getTodayDate().substr(8,2));

    if((year<2001) || (year>currentYear)){
        cout<<endl<<"The year is less than 2001 or more than current year"<<endl;
        return false;
    }
    if((year==currentYear && month >currentMonth) || (year==currentYear && month == currentMonth && day > currentDay) ){
        cout<<endl<<"The date has to be before current date."<<endl;
        return false;
    }

    if(month>12){
        cout<<endl<<"The given month is more than 12"<<endl;
        return false;
    }
    if(day>getNumberOfDays(month,year)){
        cout<<endl<<"The numbers of days is more than have given month"<<endl;
        return false;
    }
    return true;
}

int TransactionsManager::getNumberOfDays(int month, int year)
{
    if (month == 2) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
        || month == 10 || month == 12)
        return 31;
    else
        return 30;
}

