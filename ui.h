#ifndef UI_H
#define UI_H

#include<iostream>
#include"core.h"
using namespace std;

class UI
{
public:
    UI();

    void errorFile();
    void errorInput();

    void run();
    void ask();
    void menu(char ans);

    //asks what should be done with the list

    void searchMenu();
    //choose what shall be searched for
    void sortMenu();
    //choose in what order the list shall be printed
    void welcomeMessage();

    //cout setningar:

    //void individualsMatched();
    //void noMatch();
    //void inDatabase();
    //void readingString(string gender);
private:
    Core core;
};

#endif // UI_H
