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
    UI(const string filename);
    void errorFile();
    void errorInput();
    void print();
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

    void printIndi(int i) const;
    void printIndi(Individual& id) const;

    void printSize();
    void printList() const;
    void printList(People& list) const;
    void remove();

    //cout setningar:

    //void errorFile();
    //void errorInput();
    void individualsMatched();
    void noMatch();
    void inDatabase();
    void readingString(string gender);

private:
    Core core;
    Dataread data;
};

#endif // UI_H
