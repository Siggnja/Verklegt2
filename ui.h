#ifndef UI_H
#define UI_H

#include <iostream>
#include <iomanip>
#include "core.h"

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
    //Ask the user of what actions to take - sort/search/ etc...

    void sciMenu();
    void comMenu();
    void linkMenu();
    //The main menus for Scientists/Computers/Linking

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
    // Calls on print (Indi/Comp) And Connects to print lost

    void printIndiIndent(Individual &id) const;
    void printCompIndent(Computer &id) const;
    // Prints information indented, only prints id and name - used in Linking

    void printConnectedSci(People& sci) const;
    void printConnectedComp(Machines& comps) const;
    // Calls on print (Comp/Indi) indent

    void printComp(Computer& id) const;
    void printIndi(Individual& id) const;
    // Prints an individual or a computer

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
    //Clears the terminal - called upon when a new action is about to be performed
};

#endif // UI_H
