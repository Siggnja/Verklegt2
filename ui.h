#ifndef UI_H
#define UI_H

#include "core.h"
#include <iostream>
#include <iomanip>

using namespace std;

class UI
{
public:
    UI();
    void run();
    void ask();
    void menu();
    void sciMenu();
    void comMenu();
    void choiceMenu();
    void choiceSwitch(char ans);
    void linkMenu();
    void searchLinkMenu();
    void printLinkMenu();
    void menu(char ans, People& list);
    void searchComMenu();
    void searchSciMenu();
    void sortComMenu();
    void sortSciMenu();
    // Asks what you want to do

    void searchSciLink();
    void searchComLink();
    // Search functions for linked databases

    void sortSciLink();
    void sortComLink();
    // Sort functions for linked databases

    void searchComType();
    void searchComYear();
    void searchComName();
    // Search functions for computers

    void searchSciName();
    void searchGender();
    void searchBirth();
    void searchDeath();
    // Search functions for scientists

    void updateSciMenu();
    void updateIndiName(const int id);
    void updateIndiSurname(const int id);
    void updateIndiGender(const int id);
    void updateIndiBYear(const int id);
    void updateIndiDYear(const int id);
    // Functions that change information about scientists

    void updateCompMenu();
    void updateCompName(const int id);
    void updateCompBYear(const int id);
    void updateCompType(const int id);
    // Functions that change information about computers


    void welcomeMessage();
    void printIndi(Individual& id) const;


    void printList(People& list) const;
    void printComp(Computer& id) const;

    void printCompIndent(Computer &id) const;
    void printIndiIndent(Individual &id) const;
    // Prints information indented, only prints id and name

    void printIndiAndConnect(Individual & temp);
    void printCompAndConnect(Computer& temp);
    // Prints an individual or computer and all connected instances

    void printConnectedComp(Machines& comps) const;
    void printConnectedSci(People& sci) const;
    // Calls on print (Comp/Indi) indent

    void printComputersConnection(Machines &comps);
    void printScientistsConnections(People& sci);
    // Calls on print (Indi/Comp) AndConnect to print lost

    //void printComplist(Machines& list) const;
    void printComputers(Machines& comps);

    void printScientists(People& sci);

    // Print functions

    void addIndividual();
    void addComputer();
    void addConnection();
    // Add functions

    void removeSci();
    void removeCom();
    void removeConnection();
    // Remove functions

    void errorFile();
    void errorInput();
    void entriesMatched();
    void noMatch();
    void inDatabase();
    //void readingString(string gender);
    // Cout sentencses

private:
    Core core;
    void clearScreen();
};

#endif // UI_H
