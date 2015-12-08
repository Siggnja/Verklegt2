#include "machines.h"

Machines::Machines()
{

}

int Machines::getSize() const
{
    return(computers.size());
}

Computer Machines::getComputer(const int i) const
{
    return computers[i];
}

void Machines::addMach(const Computer& com)
{
    computers.push_back(com);
}
