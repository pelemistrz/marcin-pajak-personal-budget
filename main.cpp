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
            cout<<"2. Add new expense0."<<endl;
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
              personalBudget.addIncome();
            break;
            case '2':
               personalBudget.addExpense();
               break;
            case '3':
//               personalBudget.searchBySurname();
                break;
            case '4':
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






int mains(){
    string name;
    cout<< "podaj cos"<<endl;
    getline(cin,name,'\n');
    cout<< name;
    return 0;
}















