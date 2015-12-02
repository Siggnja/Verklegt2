#ifndef UI_H
#define UI_H

#include <iostream>
#include "core.h"
#include "people.h"
#include "individual.h"
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

    void menu(char ans, People& list);
    //call for changes to the list
    void searchMenu();

    void addIndividual();
    //void printIndividual();

    //
    void searchName();
    void searchGender();
    void searchBirth();
    void searchDeath();
    //

    //choose what shall be searched for

    void sortMenu();
    //choose in what order the list shall be printed
    void welcomeMessage();

    void printSize();
    void printList();

    //cout setningar:

    //void errorFile();
    //void errorInput();
    void individualsMatched();
    void noMatch();
    void inDatabase();
    void readingString(string gender);

private:
    Core core;
};

#endif // UI_H
