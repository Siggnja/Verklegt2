#include "people.h"

People::People()
{

}

void People::addIndi(const Individual& i1)
{
    person.push_back(i1);
}

vector <Individual> People::getPerson() const
{
    return person;
}
Individual People::getIndi(const int i) const
{
     return person[i];
}
int People::getSize() const
{
     return(person.size());

 }
 void People::swap(const int i, const int j)
 {
     Individual temp = person[i];
     person[i] = person[j];
     person[j] = temp;
 }
 bool People::checkIndiOrder(const int i, const int j)
 {
     string s1,s2;
     char c1,c2;
     int t1=0,t2=0;
     do
     {
        s1 = person[i].getSurname();
        s2 = person[j].getSurname();
        c1 = tolower(s1[i]);
        c2 = tolower(s2[i]);
        t1 = static_cast <int> (c1);
        int t2 = static_cast <int> (c2);
        if(t2>t1)
        {
            break;
        }
     }while(t2<t1);

     return(t2>t1);
 }

void People::removeIndi(string name)
{
    string tempName;
    vector<Individual> newlist;

    for (unsigned int i = 0; i < person.size(); i++)
    {
        tempName = person[i].getName() + " " + person[i].getSurname();
        if(tempName != name)
        {
            newlist.push_back(person[i]);
        }
    }
    person = newlist;
}

bool People::checkIndiOrder(const Individual& i1, const Individual& i2)
{
    string s1 = i1.getSurname();
    string s2 = i2.getSurname();

    int namelength = s1.size();

    for(int i = 0; i < namelength; i++)
    {
        if(static_cast<int>(tolower(s1[i])) == static_cast<int>(tolower(s2[i])))
        {
            //ekkert gerist
        }
        else
        {
            return (static_cast<int>(tolower(s1[i])) < static_cast<int>(tolower(s2[i])));
        }
    }
    int compare = s2.size();
    return(namelength < compare);

}

bool People::checkBirthYearOrder(const Individual& i1, const Individual& i2)
{
    return(i1.getBirth()>i2.getBirth());
}

bool People::checkDeathYearOrder(const Individual& i1, const Individual& i2)
{
    return(i1.getDeath()>i2.getDeath());
}
