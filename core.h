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
    void addIndividual(const Individual& ind);
    void removeIndividual(const string str);

    //functions used to search for individuals in vector with specific traits:
    //void searchName();
    void searchNam(bool& found, string searchStr, People& result);
    People searchGend(char ansGender);
    void searchBir(bool& found, int ansYear, People& result1, People& result2);
    void searchDea(bool& found, int ansYear, People& result1, People& result2);
    People getList() const;
    //sort vector by the specified order:





    string makeLower(string& temp);
    //converts the string variable temp to all lower letters */
};

#endif // CORE_H
