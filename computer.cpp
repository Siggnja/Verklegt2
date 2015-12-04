#include "computer.h"

Computer::Computer()
{

}

Computer::Computer(int idd, int yearr, string namee, string typee)
{
    id = idd;
    year = yearr;
    name = namee;
    type = typee;
}

void Computer::setId(int i)
{
    id = i;
}

void Computer::setYear(int i)
{
    year = i;
}

void Computer::setName(string str)
{
    name = str;
}

void Computer::setType(string str)
{
    type = str;
}

int Computer::getId()
{
    return id;
}

int Computer::getYear()
{
    return year;
}

string Computer::getName()
{
    return name;
}

string Computer::getType()
{
    return type;
}
