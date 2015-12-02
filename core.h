#ifndef CORE_H
#define CORE_H

#include "people.h"
#include "ui.h"
#include "dataread.h"
#include "individual.h"


class Core
{
public:
    Core();
public:
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

    //converts the string variable temp to all lower letters */

};

#endif // CORE_H
