#include "core.h"
 Core::Core()
 {

 }
 Core::Core(const People& p1)
 {

     list =p1;
 }

void Core::createList(const string filename)
{
    list = data.readData(filename);
}


int Core::getSizeOfList() const
{
    return list.getSize();
}


void Core::addIndividual(const Individual& ind,bool& notfound)
{
    notfound = checkIfIndiIsNew(ind);
    if(notfound)
    {
    list.addIndi(ind);
    data.addToFile(ind);
    }

}

void Core::removeIndividual(const string str, bool& removed)
{
    Individual temp;
    string tempstr;
    list.removeIndi(str);

    for(int i = 0; i < list.getSize(); i++)
    {
        tempstr = list.getIndi(i).getName() + " " + list.getIndi(i).getSurname();
        if(tempstr == str)
        {
            temp = list.getIndi(i);
            removed = true;
            break;
        }
    }

    for(int i = 0; i < list.getSize(); i++)
    {
        data.removeFromFile(list, temp);
    }
}

void Core::sortAlpabetFront()
{
    for(int i = 1 ; i < list.getSize(); i++)
    {
        for(int j = 0; j < list.getSize(); j++)
        {
            if(list.checkIndiOrder(list.getIndi(i),list.getIndi(j)))
            {
                list.swap(i,j);
            }
        }
    }
}

void Core::sortAlpabetBack()
{
        for(int i = 1 ; i < list.getSize(); i++)
        {
            for(int j = 0; j < list.getSize(); j++)
            {
                if(list.checkIndiOrder(list.getIndi(j),list.getIndi(i)))
                {
                    list.swap(i,j);
                }
            }
        }
}

void Core::sortByBirthYear()
{
    for(int i = 1 ; i < list.getSize(); i++)
    {
        for(int j = 0; j < list.getSize(); j++)
        {
            if(list.checkBirthYearOrder(list.getIndi(j),list.getIndi(i)))
            {
               list.swap(i,j);
            }
        }
    }
}
void Core::sortByDeathYear()
{
   // People dead, alive;
    for(int i = 1 ; i < list.getSize(); i++)
    {
        for(int j = 0; j < list.getSize(); j++)
        {
            if((list.checkDeathYearOrder(list.getIndi(j),list.getIndi(i)) && (list.getIndi(i).getDeath() != 0)))
            {
               list.swap(i,j);
            }
        }
    }
}


string Core::makeLower(string& temp)
{
    for (unsigned int i = 0; i < temp.length(); i++)
    {
        if(isupper(temp[i]))
        {
            temp[i] = tolower(temp[i]);
        }
    }
    return temp;
}


//    Search functions:

People Core::searchNam(bool& found, string searchStr, People& result)
{
    string tempStr;
    searchStr = makeLower(searchStr);
    for(int i = 0; i < list.getSize(); i++)
    {
        tempStr = list.getIndi(i).getName() + " " + list.getIndi(i).getSurname();
        tempStr = makeLower(tempStr);
        if(tempStr.find(searchStr) != string::npos)
        {
            result.addIndi(list.getIndi(i));
            found = true;
        }
    }
    return result;
}

People Core::getList() const
{
    return list;
}


People Core::searchGend(const char ansGender)
{
    char findGender;
    People result;
    for(int i = 0 ; i < 10 ; i++)
    {
        findGender = list.getIndi(i).getGender();

        if (tolower(ansGender) == tolower(findGender))
        {
            result.addIndi(list.getIndi(i));
        }
    }

    return result;
}


People Core::searchBir(bool& found, int ansYear, People& result1, People& result2)
{
    int findYear;
    for (int i = 0; i < list.getSize(); i++)
    {
        findYear = list.getIndi(i).getBirth();
        if (ansYear == findYear)
        {
            result1.addIndi(list.getIndi(i));
            found = true;
        }
        if (ansYear - 5 <= findYear && ansYear+5 >= findYear)
        {
            result2.addIndi(list.getIndi(i));
        }
    }
    if (found)
    {
        return result1;
    }
    else
    {
        return result2;
    }
}

People Core::searchDea(bool& found, int ansYear, People& result1, People& result2)
{
    int findYear;
    for (int i = 0; i < list.getSize(); i++)
    {
        findYear = list.getIndi(i).getDeath();
        if (ansYear == findYear)
        {
            result1.addIndi(list.getIndi(i));
            found = true;
        }
        if ((ansYear - 5 <= findYear && ansYear + 5 >= findYear)&&(list.getIndi(i).getDeath() != 0))
        {
            result2.addIndi(list.getIndi(i));
        }
    }
    if (found)
    {
        return result1;
    }
    else
    {
        return result2;
    }
}


string Core::getSurname(int i) const
{
    return getList().getIndi(i).getSurname();
}

string Core::getName(int i) const
{
    return getList().getIndi(i).getName();
}

int Core::getBirth(int i) const
{
    return getList().getIndi(i).getBirth();
}

int Core::getDeath(int i) const
{
    return getList().getIndi(i).getDeath();
}

char Core::getGender(int i) const
{
    return getList().getIndi(i).getGender();
}
bool Core::checkIfIndiIsNew(const Individual i1)
{
  bool check = true;
  for(int i = 0 ; i < list.getSize();i++)
  {
      if(list.getIndi(i)==i1)
      {
          check = false;
      }

  }
  return check;

}
