#ifndef MACHINES_H
#define MACHINES_H

#include "computer.h"
#include "vector"

using namespace std;


class Machines
{
public:
    Machines();

    //vector <Computer> getComputers() const;
    //void addIndi(const Individual& i1);


private:
    vector<Computer> computers;
};

#endif // MACHINES_H
