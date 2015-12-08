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

    bool searchForId(const int id, const string tablename);
    int getDatabaseSize(const string temp);

    People sortIndiAlphaFront();
    People sortIndiAlphaBack();
    People sortIndiBYear();
    People sortIndiByDYear();

    Machines sortCompAlphaFront();
    Machines sortCompAlphaBack();
    Machines sortCompBYear();
    Machines sortCompByType();

    People searchIndiByName(const string name);
    People searchIndiByByear(const int year, bool& found);
    People searchIndiByDyear(const int year, bool& found);
    People searchIndiByGender(const char gender);

    Machines searchCompByName(const string name);
    Machines searchCompByByear(const int year, bool& found);
    Machines searchCompByType(const string type);

    void updateIndiName(const string name, const int id);
    void updateIndiSurname(const string name, const int id);
    void updateIndiBYear(const int year, const int id);
    void updateIndiDYear(const int year, const int id);
    void updateIndiGender(const char gender, const int id);

    void updateCompName(const string name, const int id);
    void updateCompType(const string type, const int id);
    void updateCompBYear(const int year, const int id);

    void deleteIndi(const int id);
    void deleteComp(const int id);

    Individual getSingleIndi(const int id);
    // Gets a single Scientist based on hid id
    Computer getSingleComp(const int id);
    // Gets a single Computer based on hid id

    vector<int> getRelationsToComp(const int i);
    vector<int> getRelationsToSci(const int i);

    void createConnection(const int idSci, const int idComp);
    void deleteConnectionWithIndi(const int idSci);
    void deleteConnectionWithComp(const int idComp);
    void deleteConnectionWithIndiAndComp(const int idSci,const int idComp);
    //kollum a thessi foll thegar thad er verid a delete-a annadhvort tolvu eda indi
    // tha removar hann einnig oll tengst vid annahvort tolvuna eda scientistinn
    //spurning med thessa nafnagift -- vera samraemi her

private:
    Machines doQueryComp(const string que);
    Machines doQueryCompOrOther(const string que1, const string que2, bool& found);
    People doQuerySciOrOther(const string que1, const string qui2, bool& found);
    People doQuerySci(const string que);
    void executeQuery(const string query);
    string intToString(int i);
    QSqlDatabase db;
};

#endif // SQLITEDATA_H
