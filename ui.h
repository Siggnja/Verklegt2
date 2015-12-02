#ifndef UI_H
#define UI_H

#include "dataread.h"
#include "individual.h"
#include "core.h"
#include<iostream>

using namespace std;

class UI
{
public:
    UI();
    void run();

    void ask();
    //asks what should be done with the list
/*    void menu(char ans, People& list);
    //call for changes to the list
    void searchMenu(People& p);
    //choose what shall be searched for
    void sortMenu(People& p);
    //choose in what order the list shall be printed
    void welcomeMessage(People& p);*/

    //cout setningar:
    //void errorFile();
    //void errorInput();
    //void individualsMatched();
    //void noMatch();
    //void inDatabase();
    //void readingString(string gender);
private:
    Core c1;
};

#endif // UI_H
