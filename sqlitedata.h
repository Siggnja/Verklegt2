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
    People getIndiFromBase();
    Machines getCompFromBase();
    People sortIndiAlphaFront();
    Machines sortCompAlphaFront();
    People sortIndiAlphaBack();
    Machines sortCompAlphaBack();
private:
    void getDatabase();
    void sortAlphaFront();
<<<<<<< HEAD
=======

>>>>>>> dcc05f67ba2048864d8ac9efc3f8478b17ad89b0
};

#endif // SQLITEDATA_H
