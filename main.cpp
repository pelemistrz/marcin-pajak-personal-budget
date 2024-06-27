#include <iostream>
#include "Markup.h"
#include <cstdio>
#include <ctime>
#include <string>

#include "PersonalBudget.h"

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



















