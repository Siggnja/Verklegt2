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
};

#endif // SQLITEDATA_H
