#ifndef SQLITEDATA_H
#define SQLITEDATA_H

#include <QtSql>
#include "people.h"
#include "machines.h"
#include <iostream>
#include "globalconstants.h"
using namespace std;

class SQLiteData
{
public:
    SQLiteData();


    // Aukaföll sem hægt er að búa til
    // Machines getCompFromBase();
    // People getRelationToComp(const int i); <- skilar people sem tengjast tölvu með id i
    // Machines getRelationToIndi(const int i); <- skilar machines sem tengjast tölvunarfræðing með id i

    People sortIndiAlphaFront();
    People sortIndiAlphaBack();
    People sortIndiBYear();
    Machines sortCompAlphaFront();
    Machines sortCompAlphaBack();
    Machines sortCompBYear();
private:

    Machines doQueryComp(const string que);
    People doQuerySci(const string que);
    void getDatabase();
    void sortAlphaFront();
};

#endif // SQLITEDATA_H
