#ifndef CORE_H
#define CORE_H

#include "people.h"
#include "dataread.h"

using namespace std;

class Core
{
private:
    People list;
    Dataread data;
    void swap(const int i, const int j);
public:
    Core();
    void sortAlpabetFront();
    void sortAlpabetBack();
    void sortByBirthYear();
    void sortByDeathYear();
    void sortByGender(People& male, People& female);
    int getSizeOfList();
    void addIndividual(const Individual& ind);
    //functions used to search for individuals in vector with specific traits:
    //void searchName();
    void searchNam(bool& found, string searchStr, People& result);
    void searchGend(bool& found, char ansGender, People& result);
    void searchBir(bool& found, int ansYear, People& result1, People& result2);
    void searchDea(bool& found, int ansYear, People& result1, People& result2);
    People getList() const;
    //sort vector by the specified order:





    string makeLower(string& temp);
    //converts the string variable temp to all lower letters */
};

#endif // CORE_H
