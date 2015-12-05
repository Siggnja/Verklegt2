#ifndef SQLITEDATA_H
#define SQLITEDATA_H

#include <QtSql>
#include "people.h"
#include "machines.h"
#include "individual.h"
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
    People sortByDYear();
    People searchByByear(const int year);
    People searchByDyear(const int year);
    Individual getSingleIndi(const int id);
    Machines sortCompAlphaFront();
    Machines sortCompAlphaBack();
    Machines sortCompBYear();
    Machines sortCompByType();
    vector<int> getRelationsToComp(const int i);
    vector<int> getRelationsToSci(const int i);
    string int_to_string(int i);
private:

    Machines doQueryComp(const string que);
    People doQuerySciOrOther(const string que1, const string qui2);
    People doQuerySci(const string que);
    void getDatabase();
};

#endif // SQLITEDATA_H
