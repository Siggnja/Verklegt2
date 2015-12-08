#include "machines.h"

Machines::Machines()
{

}

void Machines::addMach(const Computer& com)
{
    computers.push_back(com);
}

void Machines::removeComputer(string name)
{
    string tempName;
    vector<Computer> newlist;

    for (unsigned int i = 0; i < computers.size(); i++)
    {
        tempName = computers[i].getName();
        if(tempName != name)
        {
            newlist.push_back(computers[i]);
        }
    }
    computers = newlist;
}

Computer Machines::getComputer(const int i) const
{
    return computers[i];
}

vector <Computer> Machines::getComs() const
{
    return computers;
}

int Machines::getSize() const
{
    return(computers.size());
}

bool Machines::checkCompOrder(const int i, const int j)
{
     string s1 = computers[i].getName();
     string s2 = computers[j].getName();

     int namelength = s1.size();

     for(int i = 0; i < namelength; i++)
     {
         if(static_cast<int>(tolower(s1[i])) == static_cast<int>(tolower(s2[i])))
         {
             // Nothing happens
         }
         else
         {
             return (static_cast<int>(tolower(s1[i])) < static_cast<int>(tolower(s2[i])));
         }
    }
    int compare = s2.size();
    return(namelength < compare);
}

bool Machines::checkCompOrder(const Computer& c1, const Computer& c2)
{
    string s1 = c1.getName();
    string s2 = c2.getName();
    int namelength = s1.size();

    for(int i = 0; i < namelength; i++)
    {
        if(static_cast<int>(tolower(s1[i])) == static_cast<int>(tolower(s2[i])))
        {
            //nothing happens
        }
        else
        {
            return (static_cast<int>(tolower(s1[i])) < static_cast<int>(tolower(s2[i])));
        }
    }
    int compare = s2.size();
    return(namelength < compare);
}

bool Machines::checkYearOrder(const Computer& c1, const Computer& c2)
{
    return(c1.getYear() > c2.getYear());
}

void Machines::swap(const int i, const int j)
{
     Computer temp = computers[i];
     computers[i] = computers[j];
     computers[j] = temp;
}
