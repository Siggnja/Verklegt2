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

    //void printIndividual();
    void searchComType();
    void searchComYear();
    void searchComName();
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

    // of mörg print föll, erum með printComputers() og printScientists()
    //void printIndi(int i) const;
    void printIndi(Individual& id) const;
    void printIndiIndent(Individual &id) const;
    //void printList() const;
    void printList(People& list) const;

    //void printComp(int i) const;
    void printComp(Computer& id) const;
    //void printComplist() const;
    void printComplist(Machines& list) const;

    void printComputers();
    void printScientists();

    void printSize();

    void addIndividual();
    void addComputer();

    void removeSci();
    void removeCom();

    // cout sentences:
    void errorFile();
    void errorInput();
    void entriesMatched();
    void noMatch();
    void inDatabase();
    void readingString(string gender);

private:
    Core core;
    Dataread data;
};

#endif // UI_H
