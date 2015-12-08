#include "people.h"

People::People()
{

}

int People::getSize() const
{
    return(person.size());
}

Individual People::getIndi(const int i) const
{
     return person[i];
}

void People::addIndi(const Individual& i1)
{
    person.push_back(i1);
}
