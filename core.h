#ifndef CORE_H
#define CORE_H

#include "people.h"
#include "dataread.h"
#include <string>

using namespace std;

class Core
{
private:
    People list;
    Dataread data;
    void swap(const int i, const int j);
    bool checkIfIndiIsNew(const Individual i1);
public:
    Core();
    Core(const People& p1);
    void createList(const string filename);

    void sortAlpabetFront();

    void sortAlpabetBack();
    void sortByBirthYear();
    void sortByDeathYear();
    void sortByGender(People& male, People& female);
    int getSizeOfList()const;
    void addIndividual(const Individual& ind, bool& notfound);
    void removeIndividual(const string str, bool& removed);

    string getSurname(int i) const;
    string getName(int i) const;
    int getBirth(int i) const;
    int getDeath(int i) const;
    char getGender(int i) const;


    //functions used to search for individuals in vector with specific traits:
    //void searchName();
    People searchGend(char ansGender);
    People searchNam(bool& found, string searchStr, People& result);
    void searchGend(bool& found, char ansGender, People& result);
    People searchBir(bool& found, int ansYear, People& result1, People& result2);
    People searchDea(bool& found, int ansYear, People& result1, People& result2);
    People getList() const;
    //sort vector by the specified order:





    string makeLower(string& temp);
    //converts the string variable temp to all lower letters */
};

#endif // CORE_H
