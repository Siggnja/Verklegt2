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
    void printIndiIndent(Individual &id) const;
    void printIndiAndConnect(Individual & temp);
    void printList(People& list) const;
    void printComp(Computer& id) const;
    void printCompIndent(Computer &id) const;
    void printCompAndConnect(Computer& temp);
    void printConnectedComp(Machines& comps) const;
    void printConnectedSci(People& sci) const;
    void printComplist(Machines& list) const;
    void printComputers(Machines& comps);
    void printComputersConnection(Machines &comps);
    void printScientists(People& sci);
    void printScientistsConnections(People& sci);
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
    void readingString(string gender);
    // Cout sentencses

private:
    Core core;
};

#endif // UI_H
