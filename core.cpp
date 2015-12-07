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


void Core::addIndividual(const Individual& ind, bool& notfound)
{
    //notfound = checkIfIndiIsNew(ind);
    /*if(notfound)
    {
        list.addIndi(ind);
        // data.addToFile(ind);
    }*/

    newdata.addNewIndi(ind,notfound);
}

void Core::removeIndividual(const int i, bool& removed)
{
    removed = true;
    newdata.deleteIndi(i);

    /*for(int i = 0; i < list.getSize(); i++)
    {
        tempstr = list.getIndi(i).getName() + " " + list.getIndi(i).getSurname();
        if(tempstr == str)
        {
            temp = list.getIndi(i);
            removed = true;
            break;
        }
    }*/

    for(int i = 0; i < list.getSize(); i++)
    {
       // data.removeFromFile(list, temp);
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

    newdata.addNewComp(com,notfound);
}

void Core::removeComputer(const int id, bool& removed)
{
    Computer temp;
    string tempstr;
    newdata.deleteComp(id);
    removed = true;
    /*
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
    }*/
}

People Core::sortSciAlpabetFront()
{
    return newdata.sortIndiAlphaFront();
}

People Core::sortSciAlpabetBack()
{
    return newdata.sortIndiAlphaBack();
}

People Core::sortSciByBirthYear()
{
    return newdata.sortIndiBYear();
}

People Core::sortSciByDeathYear()
{
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

Machines Core::getConnectedComp(int id)
{
    Machines tempMach;
    vector<int> connections= newdata.getRelationsToSci(id);
    for(unsigned int i = 0; i < connections.size(); i++)
    {
        int ident = connections[i];
        Computer tempComp = newdata.getSingleComp(ident);
        tempMach.addMach(tempComp);
    }
    return tempMach;
}

People Core::getConnectedSci(int id)
{
    People tempSci;
    vector<int> connections= newdata.getRelationsToComp(id);
    for(unsigned int i = 0; i < connections.size(); i++)
    {
        int ident = connections[i];
        Individual tempIndi = newdata.getSingleIndi(ident);
        tempSci.addIndi(tempIndi);
    }
    return tempSci;

}

People Core::getList() const
{
    return list;
}

Machines Core::getComputers() const
{
    return complist;
}

Machines Core::searchComName(string searchStr)
{
    return newdata.searchCompByName(searchStr);
}

Machines Core::searchComType(string searchStr)
{
    return newdata.searchCompByType(searchStr);
}

Machines Core::searchComYear(bool& found, int ansYear)
{
    return newdata.searchCompByByear(ansYear, found);
}

People Core::searchNam(string searchStr)
{
    return newdata.searchIndiByName(searchStr);
}

People Core::searchGend(const char ansGender)
{
    return newdata.searchIndiByGender(ansGender);
}

People Core::searchBir(bool& found, int ansYear)
{
    return newdata.searchIndiByByear(ansYear, found);
}

People Core::searchDea(bool& found, int ansYear)
{
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

int Core::getMachineSizeInNewdata()
{
    return newdata.getDatabaseSize("computer");
}

int Core::getPeopleSizeInNewdata()
{
    return newdata.getDatabaseSize("scientist");
}

void Core::updateIndiName(const string name, const int id)
{
    newdata.updateIndiName(name,id);
}

void Core::updateIndiSurname(const string name, const int id)
{
    newdata.updateIndiSurname(name,id);
}
void Core::updateIndiBYear(const int year, const int id)
{
    newdata.updateIndiBYear(year,id);
}
void Core::updateIndiDYear(const int year, const int id)
{
    newdata.updateIndiDYear(year,id);
}
void Core::updateIndiGender(const char gender, const int id)
{
    newdata.updateIndiGender(gender,id);
}
//tilgangslaust
void Core::updateIndiAll(const string name, const string surname,const char gender,const int byear,const int dyear,const int id)
{
    newdata.updateIndiName(name,id);
    newdata.updateIndiSurname(surname,id);
    newdata.updateCompBYear(byear,id);
    newdata.updateIndiDYear(dyear,id);
    newdata.updateIndiGender(gender,id);

}
void Core::updateCompName(const string name, const int id)
{

    newdata.updateCompName(name,id);
}

void Core::updateCompType(const string type, const int id)
{
    newdata.updateCompType(type,id);
}

void Core::updateCompBYear(const int year, const int id)
{
    newdata.updateCompBYear(year,id);
}
//tilgangslaust
void Core::updateCompAll(const int year,const string name,const string type,const int id)
{
    newdata.updateCompName(name,id);
    newdata.updateCompType(type,id);
    newdata.updateCompBYear(year,id);
}
SQLiteData Core::getData() const
{

    return newdata;
 }
