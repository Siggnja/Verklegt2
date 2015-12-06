#ifndef SQLITEDATA_H
#define SQLITEDATA_H

#include <QtSql>
#include "people.h"
#include "machines.h"
#include "individual.h"
#include "computer.h"
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
    People sortIndiByDYear();
    People searchIndiByName(const string name);
    People searchIndiByByear(const int year);
    People searchIndiByDyear(const int year);
    People searchIndiByGender(const char gender);
    Individual getSingleIndi(const int id);
    // Gets a single Scientist based on hid id
    Machines sortCompAlphaFront();
    Machines sortCompAlphaBack();
    Machines sortCompBYear();
    Machines sortCompByType();
    Machines searchCompByName(const string name);
    Machines searchCompByByear(const int year);
    Machines searchCompByType(const string type);
    Computer getSingleComp(const int id);
    // Gets a single Computer based on hid id
    vector<int> getRelationsToComp(const int i);
    vector<int> getRelationsToSci(const int i);
    string int_to_string(int i);
private:

    Machines doQueryComp(const string que);
    Machines doQueryCompOrOther(const string que1, const string que2);
    People doQuerySciOrOther(const string que1, const string qui2);
    People doQuerySci(const string que);
    void getDatabase();
    QSqlDatabase db;
};

#endif // SQLITEDATA_H
