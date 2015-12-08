#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "individual.h"

using namespace std;

class People
{
public:
    People();
    vector <Individual> getPerson() const;
    // Returns the vector person

    Individual getIndi(const int i) const;
    // Returns an individual at person[i]
    int getSize() const;
    // Returns the size of the vector

    void addIndi(const Individual& i1);
    // Adds an individual to vector Person
    void removeIndi(string name);
    // Removes an individual from the vector Person

    void swap(const int i, const int j);
    // Swaps the indexes of two individuals in vector

    bool checkIndiOrder(const Individual& i1, const Individual& i2);
    bool checkBirthYearOrder(const Individual& i1, const Individual& i2);
    bool checkDeathYearOrder(const Individual& i1, const Individual& i2);
    // Functions to check the order of two individuals

private:
    bool checkIndiOrder(const int i, const int j);
    vector <Individual> person;
    // A vector with elements of type Individual
};
#endif // PEOPLE_H
