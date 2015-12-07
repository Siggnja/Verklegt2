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
    //UI(const string filename);
    void run();
    void ask();
    void menu();
    void sciMenu();
    void comMenu();
    void choiceMenu();
    void choiceSwitch(char ans);
    void linkMenu();
    //asks what should be done with the list
    void searchLinkMenu();

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
    void searchSciLink();
    void searchComLink();
    //
    void updateSciMenu();
    //choose what shall be searched for
    void updateIndiName(const int id);
    void updateIndiSurname(const int id);
    void updateIndiGender(const int id);
    void updateIndiBYear(const int id);
    void updateIndiDYear(const int id);
    void updateIndiEverything(const int id);

    void sortComMenu();
    void sortSciMenu();
    //choose in what order the list shall be printed
    void welcomeMessage();

    //void printIndi(int i) const;
    void printIndi(Individual& id) const;
    void printIndiIndent(Individual &id) const;
    void printIndiAndConnect(Individual & temp);
    //void printList() const;
    void printList(People& list) const;

    //void printComp(int i) const;
    void printComp(Computer& id) const;

    void printCompIndent(Computer &id) const;
    void printConnectedComp(Machines& comps) const;

    //void printComplist() const;
    void printComplist(Machines& list) const;

    void printComputers(Machines& comps);
    void printScientists(People& sci);

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
