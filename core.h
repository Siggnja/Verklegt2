#ifndef CORE_H
#define CORE_H

#include "people.h"
#include "dataread.h"
#include "individual.h"

using namespace std;

class Core
{
private:
    People list;
    Dataread data;
public:
    Core();

    void addIndividual(const Individual& ind);
    void removeIndividual(const string str);

    //functions used to search for individuals in vector with specific traits:
    //void searchName();
    void searchNam(bool& found, string searchStr, People& result);
    void searchGend(bool& found, char ansGender, People& result);
    void searchBir(bool& found, int ansYear, People& result1, People& result2);
    void searchDea(bool& found, int ansYear, People& result1, People& result2);

    //sort vector by the specified order:
    //void sortAlpabetFront();
    void sortAlpabetFront(People& result);
    void sortAlpabetBack(People& result);

    void sortByBirthYear();
    void sortByDeathYear();
    void sortByGender();

    void swap(int& i, int& j);

    int getSizeOfList();

    string makeLower(string& temp);
    //converts the string variable temp to all lower letters
};

#endif // CORE_H
