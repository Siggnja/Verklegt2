#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <vector>
#include "individual.h"

using namespace std;
//This class stores a group of Scientists/Individuals
class People
{
public:
    People();

    int getSize() const;
    // Returns the size of the vector

    Individual getIndi(const int i) const;
    // Returns an individual at person[i]

    void addIndi(const Individual& i1);
    // Adds an individual to vector Person

private:
    vector <Individual> person;
    // A vector with elements of type Individual
};

#endif // PEOPLE_H
