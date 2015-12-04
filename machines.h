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

    //vector <Computer> getComputers() const;
    //void addIndi(const Individual& i1);
    void addMach(const Computer& com);
    vector <Computer> getComs() const;
    Computer getMach(const int i) const;
    int getSize() const;
    void swap(const int i, const int j);
    bool checkCompOrder(const int i, const int j);
    void removeComputer(string name);
    bool checkCompOrder(const Computer& c1, const Computer& c2);
    bool checkYearOrder(const Computer& c1, const Computer& c2);
private:
    vector<Computer> computers;
};

#endif // MACHINES_H
