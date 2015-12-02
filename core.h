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


    //functions used to search for individuals in vector with specific traits:
    //void searchName();
    void searchNam(bool& found, string searchStr, People& result);
    void searchGender();
    void searchBirth();
    void searchDeath();
    //sort vector by the specified order:
    void sortAlpabetFront();
    void sortAlpabetBack();
    void sortByBirthYear();
    void sortByDeathYear();
    void sortByGender();

    int getSizeOfList();

    string makeLower(string& temp);
    //converts the string variable temp to all lower letters
};

#endif // CORE_H
