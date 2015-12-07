#ifndef SQLITEDATA_H
#define SQLITEDATA_H

#include <QtSql>
#include "people.h"
#include "machines.h"
//#include "individual.h"
//#include "computer.h"
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
    void addNewIndi(const Individual i1);
    People sortIndiAlphaFront();
    People sortIndiAlphaBack();
    People sortIndiBYear();
    People sortIndiByDYear();

    People searchIndiByName(const string name);
    People searchIndiByByear(const int year, bool& found);
    People searchIndiByDyear(const int year, bool& found);
    People searchIndiByGender(const char gender);

    void updateIndiName(const string name, const int id);
    void updateIndiSurname(const string name, const int id);
    void updateIndiBYear(const int year, const int id);
    void updateIndiDYear(const int year, const int id);
    void updateIndiGender(const char gender, const int id);
    void deleteIndi(const int id);
    Individual getSingleIndi(const int id);
    // Gets a single Scientist based on hid id
    void addNewComp(const Computer c1);
    Machines sortCompAlphaFront();
    Machines sortCompAlphaBack();
    Machines sortCompBYear();
    Machines sortCompByType();
    //Here we have to give the user options to pick from the varieties of types so he can pick from,
    //and have a switch sentence which return the exact string of the type you are looking for

    Machines searchCompByName(const string name);
    Machines searchCompByByear(const int year, bool& found);
    Machines searchCompByType(const string type);

    void updateCompName(const string name, const int id);
    void updateCompType(const string type, const int id);
    void updateCompBYear(const int year, const int id);
    void deleteComp(const int id);
    Computer getSingleComp(const int id);
    // Gets a single Computer based on hid id

    vector<int> getRelationsToComp(const int i);
    vector<int> getRelationsToSci(const int i);
    void createConnection(const int idSci, const int idComp);
    void deleteConnectionWithIndi(const int idSci);
    void deleteConnectionWithComp(const int idComp);
    //kollum a thessi foll thegar thad er verid a delete-a annadhvort tolvu eda indi
    // tha removar hann einnig oll tengst vid annahvort tolvuna eda scientistinn
    //spurning med thessa nafnagift -- vera samraemi her
private:
    Machines doQueryComp(const string que);
    Machines doQueryCompOrOther(const string que1, const string que2, bool& found);
    People doQuerySciOrOther(const string que1, const string qui2, bool& found);
    People doQuerySci(const string que);
    void executeQuery(const string query);
    string int_to_string(int i);
    QSqlDatabase db;
};

#endif // SQLITEDATA_H
