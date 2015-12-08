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
    // Runs the program

    void choiceMenu();
    void choiceSwitch(char ans);

    void ask();
    void sciMenu();
    void comMenu();
    void linkMenu();

    void searchSciMenu();
    void searchComMenu();
    void searchLinkMenu();

    void sortSciMenu();
    void sortComMenu();
    void printLinkMenu();
    // Takes the user through menus of what can be done with the database

    void searchSciName();
    void searchGender();
    void searchBirth();
    void searchDeath();
    // Search functions for scientists

    void searchComName();
    void searchComType();
    void searchComYear();
    // Search functions for computers

    void searchSciLink();
    void searchComLink();
    // Search functions for linked databases

    void sortSciLink();
    void sortComLink();
    // Sort functions for linked databases

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

    void addIndividual();
    void addComputer();
    void addConnection();
    // Add functions

    void removeSci();
    void removeCom();
    void removeConnection();
    // Remove functions

    void printScientists(People& sci);
    void printComputers(Machines& comps);

    void printScientistsConnections(People& sci);
    void printComputersConnection(Machines &comps);
    // Calls on print (Indi/Comp) AndConnect to print lost

    void printIndiIndent(Individual &id) const;
    void printCompIndent(Computer &id) const;
    // Prints information indented, only prints id and name

    void printConnectedSci(People& sci) const;
    void printConnectedComp(Machines& comps) const;
    // Calls on print (Comp/Indi) indent

    void printList(People& list) const;
    void printComp(Computer& id) const;

    void printIndi(Individual& id) const;

    void printIndiAndConnect(Individual & temp);
    void printCompAndConnect(Computer& temp);
    // Prints an individual or computer and all connected instances

    void welcomeMessage();
    void errorInput();
    void entriesMatched();
    void noMatch();
    void inDatabase();
    // Cout sentencses

private:
    Core core;
    void clearScreen();
};

#endif // UI_H
