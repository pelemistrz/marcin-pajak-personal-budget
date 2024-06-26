#include <iostream>
#include "Markup.h"
#include <cstdio>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    std::time_t rawtime;
    std::tm* timeinfo;
    char buffer [30];

    std::time(&rawtime);
    timeinfo = std::localtime(&rawtime);

    std::strftime(buffer,80,"%Y-%m-%d",timeinfo);
    string todayDate = buffer;

    cout << todayDate;

//    CMarkup xml;
//    bool fileExists = xml.Load("users.xml");
//
//    if(!fileExists){
//        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
//        xml.AddElem("Users");
//    }
//
//    xml.FindElem();
//    xml.IntoElem();
//    xml.AddElem("User");
//    xml.IntoElem();
//    xml.AddElem("UserId", "2");
//    xml.AddElem("Login", "tymek");
//    xml.AddElem("Password", "tymek");
//    xml.Save("users.xml");


    return 0;
}
