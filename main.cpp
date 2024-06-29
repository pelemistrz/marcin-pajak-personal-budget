#include <iostream>
#include "Markup.h"
#include <cstdio>

#include <string>

#include "PersonalBudget.h"
#include "FileWithTransactions.h"


using namespace std;


int main()
{
    PersonalBudget personalBudget("users.xml","incomes.xml","expenses.xml");

    char choice;
    while(1)
    {
        if(personalBudget.getIdLoggedUser()==0)
        {
            cout << endl;
            cout<<"     >>> MENU GLOWNE <<<"<<endl;
            cout<<"-------------------------------"<<endl;
            cout << "1. Sign in" << endl;
            cout << "2. Log in" << endl;
            cout << "9. Exit" << endl;
            cout<<"-------------------------------"<<endl;
            cout<<"Your choice: ";
            cin >> choice;

            switch(choice) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                break;
            }
        }

        if(personalBudget.getIdLoggedUser() !=0)
        {
            cout<<endl;
            cout<<"Welcome in Personal Budget . Please choose one option: " <<endl<<endl;
            cout<<"1. Add new income."<<endl;
            cout<<"2. Add new expense."<<endl;
            cout<<"3. Show balance current month."<<endl;
            cout<<"4. Show balance previous month"<<endl;
            cout<<"5. Delete contact."<<endl;
            cout<<"6. Edit contact."<<endl;
            cout<<"7. Change password."<<endl;
            cout<<"8. Log out."<<endl;
            cout<<"9. Exit."<<endl;

            cin>>choice;

            switch(choice){
            case '1':
              personalBudget.addIncome();
            break;
            case '2':
               personalBudget.addExpense();
               break;
            case '3':
               personalBudget.showBalanceCurrentMonth();
                break;
            case '4':
                personalBudget.showBalancePreviousMonth();
                break;
            case '5':
//                personalBudget.deleteContact();
                break;
            case '6':
//               personalBudget.editContact();
                break;
            case '7':
                personalBudget.userChangePassword();
                break;
            case '8':
               personalBudget.userLogOut();
                break;
            case '9':
                exit(0);
                break;
            default:
                break;
            }
        }
    }
    return 0;
}

string getTodayDate(){
    time_t rawtime;
    tm* timeinfo;
    char todayDate [30];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(todayDate,30,"%Y%m%d",timeinfo);
    return todayDate;
}


//
//bool TransactionsManager::checkDate(string date){
//    int year;
//    int month;
//    int day;
//
//
//
//
//}

 int mains(){
     string date = "2021-04-03";
    int year = stoi(date.substr(0,4));
    int month = stoi(date.substr(5,2));
    int day = stoi(date.substr(8,2));
    cout<<year<<endl<<month<<endl<<day;
    return 0;
}















