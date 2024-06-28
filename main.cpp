#include <iostream>
#include "Markup.h"
#include <cstdio>
#include <ctime>
#include <string>

#include "PersonalBudget.h"
#include "FileWithTransactions.h"


using namespace std;

string getTodayDate();

int main()
{
    PersonalBudget personalBudget("users.xml");

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
            cout<<"1. Add new expense."<<endl;
            cout<<"2. Add new income."<<endl;
            cout<<"3. Search by surname."<<endl;
            cout<<"4. Show all contacts."<<endl;
            cout<<"5. Delete contact."<<endl;
            cout<<"6. Edit contact."<<endl;
            cout<<"7. Change password."<<endl;
            cout<<"8. Log out."<<endl;
            cout<<"9. Exit."<<endl;

            cin>>choice;

            switch(choice){
            case '1':
//              personalBudget.newContact();
            break;
            case '2':
//               personalBudget.searchByName();
               break;
            case '3':
//               personalBudget.searchBySurname();
                break;
            case '4':
                cout<<endl<<endl<<choice<<endl;
//                personalBudget.showAllContacts();
                break;
            case '5':
//                personalBudget.deleteContact();
                break;
            case '6':
//               personalBudget.editContact();
                break;
            case '7':
//                personalBudget.userChangePassword();
                break;
            case '8':
//                personalBudget.userLogOut();
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



int mains(){
    FileWithTransactions fileWithTransactions("Expenses.xml");
   // Transaction transcaction(1,1,"20240615","Food",15.0);
   // fileWithTransactions.addTransactionToTheFile(transcaction);
    vector<Transaction> t;
    t = fileWithTransactions.loadTransactionsFromFile(1);
    cout << t[0].getDate();
    return 0;
}















