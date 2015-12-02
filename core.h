#ifndef CORE_H
#define CORE_H

#include "people.h"
#include "dataread.h"


class Core
{
public:
    Core();
    void sortAlpabetFront(People p1);
    void sortAlpabetBack(const People& p1);
    void sortByBirthYear(const People& p1);
    void sortByDeathYear(const People& p1);
    void sortByGender(const People& p1);
    /*
    //functions used to search for individuals in vector with specific traits:
    void searchName();
    void searchGender();
    void searchBirth();
    void searchDeath();
    //sort vector by the specified order:
*/
private:
    void printVector();
    People p1;
    //converts the string variable temp to all lower letters */

};

#endif // CORE_H
