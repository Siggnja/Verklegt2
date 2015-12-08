#ifndef MACHINES_H
#define MACHINES_H

#include <iostream>
#include <vector>

#include "computer.h"

using namespace std;


class Machines
{
public:
    Machines();

    void addMach(const Computer& com);
    // Adds a computer to the vector
    void removeComputer(string name);
    // Removes Computer from vector

    vector <Computer> getComs() const;
    // Returns the computer vector
    int getSize() const;
    // Returns the size of the vector
    Computer getComputer(const int i) const;
    // Returns computer at vector index i

    bool checkYearOrder(const Computer& c1, const Computer& c2);
    bool checkCompOrder(const Computer& c1, const Computer& c2);
    bool checkCompOrder(const int i, const int j);
    // Checks the order of computers

    void swap(const int i, const int j);
    // Swaps two vector indexes

private:
    vector<Computer> computers;
};

#endif // MACHINES_H
