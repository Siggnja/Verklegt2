#ifndef SQLITEDATA_H
#define SQLITEDATA_H

#include <QtSql>
#include <iostream>
#include "people.h"
#include "machines.h"
#include "globalconstants.h"

using namespace std;

class SQLiteData
{
public:
    SQLiteData();

    void addNewIndi(const Individual i1,bool& found);
    void addNewComp(const Computer c1,bool& notfound);
    // Adds a new scientist or computer to database

    void deleteIndi(const int id);
    void deleteComp(const int id);
    // Deletes a scientist or computer from database

    People sortIndiAlphaFront();
    People sortIndiAlphaBack();
    People sortIndiBYear();
    People sortIndiByDYear();
    // Returns a people vector where the elements have been sorted

    Machines sortCompAlphaFront();
    Machines sortCompAlphaBack();
    Machines sortCompBYear();
    Machines sortCompByType();
    // Returns a machine vector where the elements have been sorted

    People searchIndiByName(const string name);
    People searchIndiByByear(const int year, bool& found);
    People searchIndiByDyear(const int year, bool& found);
    People searchIndiByGender(const char gender);
    // Returns a people vector containing elements that fit the search criteria

    Machines searchCompByName(const string name);
    Machines searchCompByByear(const int year, bool& found);
    Machines searchCompByType(const string type);
    // Return a machine vector containing elements that fit the search criteria

    void updateIndiName(const string name, const int id);
    void updateIndiSurname(const string name, const int id);
    void updateIndiBYear(const int year, const int id);
    void updateIndiDYear(const int year, const int id);
    void updateIndiGender(const char gender, const int id);
    // Changes information about a scientist

    void updateCompName(const string name, const int id);
    void updateCompType(const string type, const int id);
    void updateCompBYear(const int year, const int id);
    // Changes information about a computer

    void createConnection(const int idSci, const int idComp);
    // Creates a connection between a scientist and a computer

    void deleteConnectionWithIndi(const int idSci);
    void deleteConnectionWithComp(const int idComp);
    void deleteConnectionWithIndiAndComp(const int idSci, const int idComp);
    // Deletes a connection between a scientist and a computer

    bool searchForId(const int id, const string tablename);
    // Checks if a specified id can be found in the specified table
    int getDatabaseSize(const string temp);
    // Returns the size of specified database

    vector<int> getRelationsToComp(const int i);
    // Returns a vector containing relations to computers
    vector<int> getRelationsToSci(const int i);
    // Returns a vector containing relations to scientists

    Individual getSingleIndi(const int id);
    // Returns a single Scientist based on hid id
    Computer getSingleComp(const int id);
    // Returns a single Computer based on hid id

private:
    QSqlDatabase db;

    string intToString(int i);
    // Converts an integer variable to a string variable

    Machines doQueryComp(const string que);
    Machines doQueryCompOrOther(const string que1, const string que2, bool& found);
    People doQuerySciOrOther(const string que1, const string qui2, bool& found);
    People doQuerySci(const string que);
    void executeQuery(const string query);
    // Execute a specified query
};

#endif // SQLITEDATA_H
