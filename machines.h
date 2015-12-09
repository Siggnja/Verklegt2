#ifndef MACHINES_H
#define MACHINES_H

#include <iostream>
#include <vector>
#include "computer.h"

using namespace std;
//This class stores a group of Computers
class Machines
{
public:
    Machines();

    int getSize() const;
    // Returns the size of the vector

    Computer getComputer(const int i) const;
    // Returns computer at vector index i

    void addMach(const Computer& com);
    // Adds a computer to the vector

private:
    vector<Computer> computers;
    // A vector with elements of type Computer
};

#endif // MACHINES_H
