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
    Machines getCompFromBase();
    People sortIndiAlphaFront();
    Machines sortCompAlphaFront();
    People sortIndiAlphaBack();
    Machines sortCompAlphaBack();
private:
    void getDatabase();
};

#endif // SQLITEDATA_H
