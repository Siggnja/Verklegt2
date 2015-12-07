#include "core.h"

Core::Core()
{

}

Core::Core(const People& p1)
{
    list = p1;
}

void Core::setList(const People p1)
{
    list = p1;
}

void Core::setComplist(const Machines c1)
{
    complist = c1;
}

void Core::createList(const string filename)
{
    list = data.readData(filename);
}

int Core::getSizeOfList() const
{
    return list.getSize();
    //  query.exec("SELECT count(*)"); -- nota þetta til að fá stærð
}

int Core::getSizeOfComplist() const
{
    return complist.getSize();
    //  query.exec("SELECT count(*)"); -- nota þetta til að fá stærð
}

void Core::addIndividual(const Individual& ind, bool& notfound)
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

void Core::addComputer(const Computer& com, bool& notfound)
{
    /*notfound = checkIfComIsNew(ind);
    if(notfound)
    {
        list.addIndi(ind);
        data.addToFile(ind);
    }*/
}

void Core::removeComputer(const string str, bool& removed)
{
    Computer temp;
    string tempstr;
    complist.removeComputer(str);

    for(int i = 0; i < complist.getSize(); i++)
    {
        tempstr = complist.getComputer(i).getName();
        if(tempstr == str)
        {
            temp = complist.getComputer(i);
            removed = true;
            break;
        }
    }

    for(int i = 0; i < complist.getSize(); i++)
    {
        //data.removeFromFile(complist, temp);
    }
}

People Core::sortSciAlpabetFront()
{

/*    for(int i = 1 ; i < list.getSize(); i++)
    {
        for(int j = 0; j < list.getSize(); j++)
        {
            if(list.checkIndiOrder(list.getIndi(i), list.getIndi(j)))
            {
                list.swap(i,j);
            }
        }
    }*/
    return newdata.sortIndiAlphaFront();
}

People Core::sortSciAlpabetBack()
{
/*    for(int i = 1 ; i < list.getSize(); i++)
    {
        for(int j = 0; j < list.getSize(); j++)
        {
            if(list.checkIndiOrder(list.getIndi(j), list.getIndi(i)))
            {
                    list.swap(i,j);
            }
        }
    }*/
    return newdata.sortIndiAlphaBack();
}

People Core::sortSciByBirthYear()
{
/*    for(int i = 1 ; i < list.getSize(); i++)
    {
        for(int j = 0; j < list.getSize(); j++)
        {
            if(list.checkBirthYearOrder(list.getIndi(j), list.getIndi(i)))
            {
               list.swap(i,j);
            }
        }
    }*/
    return newdata.sortIndiBYear();
}

People Core::sortSciByDeathYear()
{
   // People dead, alive;
    /*    for(int i = 1 ; i < list.getSize(); i++)
    {
        for(int j = 0; j < list.getSize(); j++)
        {
            if((list.checkDeathYearOrder(list.getIndi(j), list.getIndi(i)) && (list.getIndi(i).getDeath() != 0)))
            {
               list.swap(i,j);
            }
        }
    }
    People origin = newdata.sortIndiByDYear();
    People dead, alive;

    for(int i = 0; i < origin.getSize(); i++)
    {
        if(origin.getIndi(i).getDeath() == 0)
        {
           alive.addIndi(origin.getIndi(i));
        }
        else
        {
            dead.addIndi(origin.getIndi(i));
        }
    }

    for(int i = 0; i < alive.getSize(); i++)
    {
        dead.addIndi(alive.getIndi(i));
    }

    return dead;*/
    return newdata.sortIndiByDYear();
}

Machines Core::sortCompAlpabetFront()
{
    return newdata.sortCompAlphaFront();
}

Machines Core::sortCompAlpabetBack()
{
    return newdata.sortCompAlphaBack();
}

Machines Core::sortCompBuildYear()
{
    return newdata.sortCompBYear();
}

Machines Core::sortCompType()
{
    return newdata.sortCompByType();
}

/*string Core::makeLower(string& temp)
{
    for (unsigned int i = 0; i < temp.length(); i++)
    {
        if(isupper(temp[i]))
        {
            temp[i] = tolower(temp[i]);
        }
    }
    return temp;
}*/

Machines Core::getConnectedComp(int id)
{
    Machines tempMach;
    vector<int> connections= newdata.getRelationsToSci(id);
    for(unsigned int i = 0; i < connections.size(); i++)
    {
        cout << "getting comp" << endl;
        int ident = connections[i];
        Computer tempComp = newdata.getSingleComp(ident);
        cout << "-" << tempComp.getName() << "-" << endl;
    }
    return tempMach;
}

People Core::getList() const
{
    return list;
}

Machines Core::getComputers() const
{
    return complist;
}

Machines Core::searchComName(string searchStr, Machines& result)
{
    return newdata.searchCompByName(searchStr);
}

Machines Core::searchComType(string searchStr, Machines& result)
{
    return newdata.searchCompByType(searchStr);
}

Machines Core::searchComYear(bool& found, int ansYear, Machines& result1, Machines& result2)
{
    return newdata.searchCompByByear(ansYear);
}

People Core::searchNam(bool& found, string searchStr, People& result)
{
    /*string tempStr;
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
    return result;*/
    return newdata.searchIndiByName(searchStr);
}

People Core::searchGend(const char ansGender)
{
    /*char findGender;
    People result;
    for(int i = 0 ; i < 10 ; i++)
    {
        findGender = list.getIndi(i).getGender();
        if (tolower(ansGender) == tolower(findGender))
        {
            result.addIndi(list.getIndi(i));
        }
    }
    return result;*/
    return newdata.searchIndiByGender(ansGender);
}

People Core::searchBir(bool& found, int ansYear, People& result1, People& result2)
{
    /*int findYear;
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
    }*/
    return newdata.searchIndiByByear(ansYear, found);
}

People Core::searchDea(bool& found, int ansYear, People& result1, People& result2)
{
    /*int findYear;
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
    }*/
    return newdata.searchIndiByDyear(ansYear, found);
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

string Core::getCompname(int i) const
{
    return getComputers().getComputer(i).getName();
}

string Core::getComptype(int i) const
{
    return getComputers().getComputer(i).getType();
}

int Core::getYear(int i) const
{
    return getComputers().getComputer(i).getYear();
}

int Core::id(int i) const
{
    return getComputers().getComputer(i).getId();
}

bool Core::checkIfIndiIsNew(const Individual i1)
{
    bool check = true;
    for(int i = 0; i < list.getSize(); i++)
    {
        if(list.getIndi(i) == i1)
        {
            check = false;
        }
    }
    return check;
}
void Core::createConnection(const Individual& i1, const Computer& c1, bool& found)
{
    vector <int> relComp = newdata.getRelationsToComp(c1.getId());
    for(unsigned int i =0 ; i < relComp.size();i++)
    {
        if(relComp[i]==i1.getId())
        {
            found = true;
        }
    }
    if(!found)
    {
    newdata.createConnection(i1.getId(),c1.getId());
    }
}
void Core::deleteConnectionWithIndi(const Individual& i1, bool& found)
{
    vector <int> relIndi = newdata.getRelationsToSci(i1.getId());
    if(relIndi.size()!=0)
    {
        found = false;
    }
    if(found)
    {
    newdata.deleteConnectionWithIndi(i1.getId());
    }
}
void Core::deleteConnectionWithComp(const Computer& c1,bool& found)
{
    vector <int> relComp = newdata.getRelationsToComp(c1.getId());
    if(relComp.size()!=0)
    {
        found = true;
    }
    if(found)
    {
    newdata.deleteConnectionWithIndi(c1.getId());
    }
}
