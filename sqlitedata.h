#ifndef SQLITEDATA_H
#define SQLITEDATA_H
#include <QtSql>
#include "people.h"
#include "individual.h"
#include <iostream>

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

};

#endif // SQLITEDATA_H
