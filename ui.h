#ifndef UI_H
#define UI_H

//#include "dataread.h"
#include "core.h"
#include <iostream>
using namespace std;

class UI
{
public:
    UI();
    UI(const string filename);
    void print();
    void run();
    void ask();
    void menu();
    void sciMenu();
    void comMenu();
    void choiceMenu();
    void choiceSwitch(char ans);
    //asks what should be done with the list

    void menu(char ans, People& list);
    //call for changes to the list
    void searchComMenu();
    void searchSciMenu();

    void addIndividual();
    //void printIndividual();

    //
    void searchSciName();
    void searchGender();
    void searchBirth();
    void searchDeath();
    //

    //choose what shall be searched for

    void sortComMenu();
    void sortSciMenu();
    //choose in what order the list shall be printed
    void welcomeMessage();

    void printIndi(int i) const;
    void printIndi(Individual& id) const;

    void printSize();
    void printList() const;
    void printList(People& list) const;
    void remove();

    // cout sentences:
    void errorFile();
    void errorInput();
    void individualsMatched();
    void noMatch();
    void inDatabase();
    void readingString(string gender);
    void addComputer();
    void printComputer();

private:
    Core core;
    Dataread data;
};

#endif // UI_H
