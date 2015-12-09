#ifndef CORE_H
#define CORE_H

#include <iostream>
#include "people.h"
#include "machines.h"
#include "sqlitedata.h"

using namespace std;

class Core
{
public:
    Core();

    SQLiteData getData() const;
    // Returns the newdata variable

    People sortSciAlpabetFront();
    People sortSciAlpabetBack();
    People sortSciByBirthYear();
    People sortSciByDeathYear();
    // Returns a sorted People class variable

    void addIndividual(const Individual& ind, bool& notfound);
    void addComputer(const Computer& com, bool& notfound);
    void addConnection(const int idSci, const int idComp);
    // Add to database Scientists, Computers, Connections

    void removeIndividual(const int i, bool& removed);
    void removeComputer(const int id, bool& removed);
    void removeConnection(const int idSci, const int idComp);
    // Removes from database Scientists, Computers, Connections

    string getSurname(int i) const;
    string getName(int i) const;
    int getBirth(int i) const;
    int getDeath(int i) const;
    char getGender(int i) const;
    // Returns variables from Individual at index i in People

    string getCompname(int i) const;
    string getComptype(int i) const;
    int getYear(int i) const;
    int id(int i) const;
    // Returns variables from Computer at index i in Machines

    People searchGend(char ansGender);
    People searchNam(string searchStr);
    People searchGend(bool& found, char ansGender, People& result);
    People searchBir(bool& found, int ansYear);
    People searchDea(bool& found, int ansYear);
    // Functions used to search for Individuals in database with specific traits

    Machines searchComName(string searchStr);
    Machines searchComType(string searchStr);
    Machines searchComYear(bool& found, int ansYear);
    // Functions used to search for Computers in database with specific traits

    Machines sortCompAlpabetFront();
    Machines sortCompAlpabetBack();
    Machines sortCompBuildYear();
    Machines sortCompType();
    // Returns a sorted Machine class variable

    void updateIndiName(const string name, const int id);
    void updateIndiSurname(const string name, const int id);
    void updateIndiBYear(const int year, const int id);
    void updateIndiDYear(const int year, const int id);
    void updateIndiGender(const char gender, const int id);
    // Changes values inside Scientist table

    void updateCompName(const string name, const int id);
    void updateCompType(const string type, const int id);
    void updateCompBYear(const int year, const int id);
    // Changes values inside Computer table

    //void updateIndiAll(const string name, const string surname,const char gender,const int byear,const int dyear, const int id);
    //void updateCompAll(const int year,const string name,const string type,const int id);
    //Functions not being used in current version of program

    Machines getConnectedComp(int id);
    People getConnectedSci(int id);
    // Returns all Computers/Scientists connected to id i

    People getList() const;
    Machines getComputers() const;
    // Get functions

    void setList(const People p1);
    void setComplist(const Machines c1);
    // Set funtions

    void createConnection(const Individual& i1, const Computer& c1, bool& found);
    // Creates connections between a Scientist and a Computer

    int getMachineSizeInNewdata();
    int getPeopleSizeInNewdata();
    // Returns the size of the database

private:
    People list;
    Machines complist;
    SQLiteData newdata;
};

#endif // CORE_H
