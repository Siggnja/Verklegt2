#include "core.h"

Core::Core()
{
    list = data.readData();
}

int Core::getSizeOfList()
{
    return list.getSize();
}

void Core::swap(int& i, int& j)
{
    int temp = i;
    i = j;
    j = temp;
}

void Core::addIndividual(const Individual& ind)
{
    list.addIndi(ind);
    data.addToFile(ind);
}

void Core::removeIndividual(const string str)
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
            break;
        }
    }

    for(int i = 0; i < list.getSize(); i++)
        data.removeFromFile(list, temp);
}


/*  Sort functions:

void People::sortAlpabetFront()
{
    People result(*this);
    for(unsigned int i = 1 ; i < result.person.size(); i++)
    {
        for(unsigned int j = 0; j < result.person.size(); j++)
        {
            if(result.checkIndiOrder(result.person[i],result.person[j]))
            {
                result.swap(j,i);
            }
        }
    }
    result.printVector();
}*/

void Core::sortAlpabetFront(People& result)
{
    //People result(*this);
    for(int i = 1 ; i < result.getSize(); i++)
    {
        for(int j = 0; j < result.getSize(); j++)
        {
            if(result.checkIndiOrder(result.getIndi(i),result.getIndi(j)))
            {
                //result.swap(j,i);
                swap(j,i);
            }
        }
    }
    //result.printVector();
}


/*void People::sortAlpabetBack()
{
    People result(*this);
    for(unsigned int i = 1 ; i < result.person.size(); i++)
    {
        for(unsigned int j = 0; j < result.person.size(); j++)
        {
            if(result.checkIndiOrder(result.person[j],result.person[i]))
            {
                result.swap(j,i);
            }
        }
    }
   result.printVector();
}*/

void Core::sortAlpabetBack(People& result)
{
    //People result(*this);
    for(int i = 1 ; i < result.getSize(); i++)
    {
        for(int j = 0; j < result.getSize(); j++)
        {
            if(result.checkIndiOrder(result.getIndi(j),result.getIndi(i)))
            {
                //result.swap(j,i);
                swap(j,i);
            }
        }
    }
    //result.printVector();
}

/*void People::sortByBirthYear()
{
    People result(*this);
    for(unsigned int i = 1 ; i < result.person.size(); i++)
    {
        for(unsigned int j = 0; j < result.person.size(); j++)
        {
            if(result.checkBirthYearOrder(result.person[j],result.person[i]))
            {
                result.swap(j,i);
            }
        }
    }
   result.printVector();
}

void People::sortByDeathYear()
{
    People result(*this);
    People dead, alive;
    for(unsigned int i = 1 ; i < result.person.size(); i++)
    {
        for(unsigned int j = 0; j < result.person.size(); j++)
        {
            if(result.checkDeathYearOrder(result.person[j],result.person[i]))
            {
                result.swap(j,i);
            }
        }
    }
    for(unsigned int i = 0; i < result.person.size(); i++)
    {
        if(result.person[i].getDeath()!=0)
        {
            dead.person.push_back(result.getIndi(i));
        }
        else
        {
            alive.person.push_back(result.getIndi(i));
        }
    }
    dead.printVector();
    alive.sortAlpabetFront();
}

void People::sortByGender()
{
    People r1(*this);
    People male,female;
    char ans;
    cout << "Do you want to sort by male(m) or female(f)? " ;
    cin >> ans;
    for(unsigned int j = 0; j<r1.person.size(); j++)
    {
        if(r1.getIndi(j).getGender() == 'm' || r1.getIndi(j).getGender()=='M')
        {
            male.person.push_back(r1.person[j]);
        }
        else
        {
            female.person.push_back(r1.person[j]);
        }
    }
    if(ans == 'm' || ans == 'M')
    {
        cout << "--- Reading males ---" << endl;
        male.sortAlpabetFront();
        cout << "--- Reading females ---" << endl;
        female.sortAlpabetFront();
    }
    else if(ans == 'f' || ans == 'F')
    {
        cout << "--- Reading females ---" << endl;
        female.sortAlpabetFront();
        cout << "--- Reading males ---" << endl;
        male.sortAlpabetFront();
    }
    else
    {
        cout << "Wrong input try again" << endl;
        this->sortByGender();
    }
}

*/

// ////////////////////////////////////////////////////////////////////////////////////////////////////

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

/*void Core::searchName()
{
    People result;
    bool found = false;
    string tempStr, searchStr = "";
    cin.ignore();   //annars virkar getline ekki
    cout << "Enter a name to search for: " ;
    getline(cin, searchStr);
    searchStr = makeLower(searchStr);

    for(int i = 0; i < list.getSize(); i++)
    {
        tempStr = list.getIndi(i).getName() + " " + list.getIndi(i).getSurname();
        tempStr = makeLower(tempStr);
        if(tempStr.find(searchStr) != string::npos)
        {
            result.addIndi(result.getIndi(i));
            found = true;
        }
    }
    //result.sortAlpabetFront();
    //sortAlpabetFront();
    if (found == false)
    {
        //ui.noMatch();
    }
}*/

void Core::searchNam(bool& found, string searchStr, People& result)
{
    string tempStr;
    searchStr = makeLower(searchStr);
    for(int i = 0; i < list.getSize(); i++)
    {
        tempStr = list.getIndi(i).getName() + " " + list.getIndi(i).getSurname();
        tempStr = makeLower(tempStr);
        if(tempStr.find(searchStr) != string::npos)
        {
            result.addIndi(result.getIndi(i));
            found = true;
        }
    }

    sortAlpabetFront(result);
    //sortAlpabetFront();

}
/*
void Core::searchGender()
{
    People result;
    bool found = false;
    char findGender, ansGender;
    cout << endl;
    cout << "Enter which gender you want to search for (m/f): ";
    cin >> ansGender;
    cout << endl;
    if(ansGender == 'm' || ansGender == 'M' || ansGender=='f' || ansGender=='F')
    {
        //ui.individualsMatched();
        for (int i = 0; i < list.getSize(); i++)
        {
            findGender = list.getIndi(i).getGender();
            if (tolower(ansGender) == tolower(findGender))
            {
                result.addIndi(result.getIndi(i));
                found = true;
            }
        }
        //result.sortAlpabetFront();
        //sortAlpabetFront();
    }
    else
    {
        //ui.errorInput();
        this->searchGender();
    }
    if (found == false)
    {
        //ui.noMatch();
    }
}*/

void Core::searchGend(bool& found, char ansGender, People& result)
{
    char findGender;
    for (int i = 0; i < list.getSize(); i++)
    {
        findGender = list.getIndi(i).getGender();
        if (tolower(ansGender) == tolower(findGender))
        {
            result.addIndi(result.getIndi(i));
            found = true;
        }
    }
    sortAlpabetFront(result);
}



/*void Core::searchBirth()
{
    People result1, result2;
    bool found = false;
    int findYear, ansYear;
    cout << "Enter a birth year: ";
    cin >> ansYear;
    if(!cin.fail())
    {
        //ui.individualsMatched();
        for (int i = 0; i < list.getSize(); i++)
        {
            findYear = list.getIndi(i).getBirth();
            if (ansYear == findYear)
            {
                result1.addIndi(result1.getIndi(i));
                found = true;
            }
            if (ansYear - 5 <= findYear && ansYear+5 >= findYear)
            {
                result2.addIndi(result2.getIndi(i));
            }
        }
        if(found)
        {
            //result1.sortAlpabetFront();
            //sortAlpabetFront();
        }
        if (found == false)
        {
            //ui.individualsMatched();
                if(result2.getSize() != 0)
                {
                    cout << "However these individuals were found within"
                            " a 10 year range of given year: " << endl;
                    cout << "--- Printing by alphabetical order ---" << endl;
                    //result2.sortAlpabetFront();
                    //sortAlpabetFront();
                }
        }
    }
    else
    {
        //ui.errorInput();
        cin.clear();
        cin.ignore();
        this->searchBirth();
    }
}*/

void Core::searchBir(bool& found, int ansYear, People& result1, People& result2)
{
    int findYear;
    for (int i = 0; i < list.getSize(); i++)
    {
        findYear = list.getIndi(i).getBirth();
        if (ansYear == findYear)
        {
            result1.addIndi(result1.getIndi(i));
            found = true;
        }
        if (ansYear - 5 <= findYear && ansYear+5 >= findYear)
        {
            result2.addIndi(result2.getIndi(i));
        }
    }
}

/*void Core::searchDeath()
{
    People result1, result2;
    bool found = false;
    int findYear, ansYear;
    cout << "Enter a death year: ";
    cin >> ansYear;
    if(!cin.fail())
    {
        //ui.individualsMatched();
        for (int i = 0; i < list.getSize(); i++)
        {
            findYear = list.getIndi(i).getDeath();
            if (ansYear == findYear)
            {
                result1.addIndi(result1.getIndi(i));
                found = true;
            }
            if (ansYear - 5 <= findYear && ansYear + 5 >= findYear)
            {
                result2.addIndi(result2.getIndi(i));
            }
        }
        if(found)
        {
            //result1.sortAlpabetFront();
            //sortAlpabetFront();
        }
        if (found == false)
        {
            //ui.errorInput();
                if(result2.getSize() != 0)
                {
                    cout << "However these individuals were found within"
                            " a 10 year range of given year: " << endl;
                    //result2.sortAlpabetFront();
                    //sortAlpabetFront();
                }
        }
    }
    else
    {
        //ui.errorInput();
        cin.clear();
        cin.ignore();
        this->searchDeath();

    }
}*/

void Core::searchDea(bool& found, int ansYear, People& result1, People& result2)
{
    int findYear;
    for (int i = 0; i < list.getSize(); i++)
    {
        findYear = list.getIndi(i).getDeath();
        if (ansYear == findYear)
        {
            result1.addIndi(result1.getIndi(i));
            found = true;
        }
        if (ansYear - 5 <= findYear && ansYear + 5 >= findYear)
        {
            result2.addIndi(result2.getIndi(i));
        }
    }
}
