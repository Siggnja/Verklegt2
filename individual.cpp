#include "individual.h"

Individual::Individual()
{

}

Individual::Individual(const string surnam, const string nam, const char gend, const int bir, const int dea)
{
    name = nam;
    surname = surnam;
    gender = gend;
    birth = bir;
    death = dea;
}
<<<<<<< HEAD
=======

>>>>>>> c3ecd5d30ff9ac479edaf836ed24bb2d316266e7
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
<<<<<<< HEAD
/*
ostream& operator << (ostream& outs, Individual& id)
{
    outs << "Name: " << id.surname << ", " << id.name << endl;
    outs << "Gender: " << id.gender << endl;
    outs << "Year of birth: " << id.birth << endl;
    if (id.death == 0)
    {
        outs << "The individual is still alive." << endl;
    }
    else
    {
        outs << "Year of death: " << id.death << endl;
    }
    return outs;
}

istream& operator >> (istream& ins, Individual& id)
=======

void Individual::setName(string str)
>>>>>>> c3ecd5d30ff9ac479edaf836ed24bb2d316266e7
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
<<<<<<< HEAD
*/
=======



>>>>>>> c3ecd5d30ff9ac479edaf836ed24bb2d316266e7
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

