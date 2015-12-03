#include "individual.h"

Individual::Individual()
{

}

Individual::Individual(const string surnam, const string nam, const char gend, const int bir, const int dea)
{
    id = 1;
    name = nam;
    surname = surnam;
    gender = gend;
    birth = bir;
    death = dea;
}
bool operator == (const Individual& indi, const Individual& indi2)
{
    if (indi.birth == indi2.birth && indi.death == indi2.death && indi.surname == indi2.surname
       && indi.gender == indi2.gender && indi.name == indi2.name)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Individual::setName(string str)
{
    name = str;
}

void Individual::setSurname(string str)
{
    name = str;
}

void Individual::setGender(char g)
{
    gender = g;
}

void Individual::setBirth(int i)
{
    birth = i;
}

void Individual::setDeath(int i)
{
    death = i;
}

string Individual::getName() const
{
    return name;
}

string Individual::getSurname() const
{
    return surname;
}

char Individual::getGender() const
{
    return gender;
}

int Individual::getBirth() const
{
    return birth;
}

int Individual::getDeath() const
{
    return death;
}

