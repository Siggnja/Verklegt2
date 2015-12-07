#ifndef CORE_H
#define CORE_H

#include "people.h"
#include "machines.h"
#include "sqlitedata.h"
#include <string>

using namespace std;

class Core
{
private:
    People list;
    Machines complist;
    SQLiteData newdata;
    void swap(const int i, const int j);
    bool checkIfIndiIsNew(const Individual i1);
public:
    Core();
    Core(const People& p1);
    SQLiteData getData() const;

    void createList(const string filename);

    People sortSciAlpabetFront();
    People sortSciAlpabetBack();
    People sortSciByBirthYear();
    People sortSciByDeathYear();
    //void sortByGender(People& male, People& female);

    void addIndividual(const Individual& ind, bool& notfound);
    void addComputer(const Computer& com, bool& notfound);
    void removeIndividual(const string str, bool& removed);
    void removeComputer(const string str, bool& removed);

    string getSurname(int i) const;
    string getName(int i) const;
    int getBirth(int i) const;
    int getDeath(int i) const;
    char getGender(int i) const;

    string getCompname(int i) const;
    string getComptype(int i) const;
    int getYear(int i) const;
    int id(int i) const;

    //functions used to search for individuals in vector with specific traits:
    //void searchName();
    People searchGend(char ansGender);
    People searchNam(string searchStr);
    People searchGend(bool& found, char ansGender, People& result);
    People searchBir(bool& found, int ansYear);
    People searchDea(bool& found, int ansYear);
     //<--
    //sort vector by the specified order:

    Machines searchComName(string searchStr);
    Machines searchComType(string searchStr);
    Machines searchComYear(bool& found, int ansYear);

    Machines sortCompAlpabetFront();
    Machines sortCompAlpabetBack();
    Machines sortCompBuildYear();
    Machines sortCompType();

    void updateIndiName(const string name, const int id);
    void updateIndiSurname(const string name, const int id);
    void updateIndiBYear(const int year, const int id);
    void updateIndiDYear(const int year, const int id);
    void updateIndiGender(const char gender, const int id);
    void updateIndiAll(const string name, const string surname,const char gender,const int byear,const int dyear, const int id);

    void updateCompName(const string name, const int id);
    void updateCompType(const string type, const int id);
    void updateCompBYear(const int year, const int id);
    void updateCompAll(const int year,const string name,const string type,const int id);
    Machines getConnectedComp(int id);
    People getConnectedSci(int id);

    People getList() const;
    Machines getComputers() const;
    void setList(const People p1);
    void setComplist(const Machines c1);

    void createConnection(const Individual& i1, const Computer& c1,bool& found);
    void deleteConnectionWithIndi(const Individual& i1,bool& found);
    void deleteConnectionWithComp(const Computer& i1,bool& found);

    string makeLower(string& temp);
    //converts the string variable temp to all lower letters */

    int getMachineSizeInNewdata();
    int getPeopleSizeInNewdata();
};

#endif // CORE_H
