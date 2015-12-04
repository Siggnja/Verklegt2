#ifndef SQLITEDATA_H
#define SQLITEDATA_H
#include <QtSql>
#include "people.h"
#include "individual.h"
#include "machines.h"
#include <iostream>
#include "globalconstants.h"
using namespace std;

class SQLiteData
{
public:
    SQLiteData();
    People getIndiFromBase();


    // Aukaföll sem hægt er að búa til
    // Machines getCompFromBase();
    // People getRelationToComp(const int i); <- skilar people sem tengjast tölvu með id i
    // Machines getRelationToIndi(const int i); <- skilar machines sem tengjast tölvunarfræðing með id i


    Machines getCompFromBase();
    People sortIndiAlphaFront();
    Machines sortCompAlphaFront();
    People sortIndiAlphaBack();
    Machines sortCompAlphaBack();
private:
    void getDatabase();
=======
    void sortAlphaFront();

>>>>>>> df382e82feccaf73c806ea9b80c1123286571a21
};

#endif // SQLITEDATA_H
