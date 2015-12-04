#ifndef SQLITEDATA_H
#define SQLITEDATA_H
#include <QtSql>
#include "people.h"
#include "individual.h"
#include "machines.h"
#include <iostream>

using namespace std;

class SQLiteData
{
public:
    SQLiteData();
    People getIndiFromBase();
    Machines getCompFromBase();
};

#endif // SQLITEDATA_H
