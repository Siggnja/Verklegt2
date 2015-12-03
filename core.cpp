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


void Core::addIndividual(const Individual& ind)
{
    list.addIndi(ind);
    data.addToFile(ind);
}

//void sortAlpabetBack(const People& p1)
//void sortByBirthYear(const People& p1)
//void sortByDeathYear(const People& p1)
//void sortByGender(const People& p1)
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
    {
        data.removeFromFile(list, temp);
    }
    cout << str << " hase been removed." << endl;
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
            if(list.checkDeathYearOrder(list.getIndi(j),list.getIndi(i)))
            {
               list.swap(i,j);
            }
        }
    }
}
/*
void Core::sortByGender(People& male, People& female)
{

        for(int j = 0; j<list.getSize(); j++)
        {
            if(list.getIndi(j).getGender() == 'm' || list.getIndi(j).getGender()=='M')
            {
                male.addIndi(list.getIndi(j));
            }
            else
            {
                female.addIndi(list.getIndi(j));
            }
        }
    // verdur svo ad kalla a sort by alphabet i ui
}
    for(int i = 0; i < list.getSize(); i++)
    {
       if(list.getIndi(i).getDeath()!=0)
        {
            dead.person.push_back(list.getIndi(i));
        }
        else
        {
            alive.person.push_back(list.getIndi(i));
        }
    }
    dead.printVector();
    alive.sortAlpabetFront();
}


*/

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
            result.addIndi(list.getIndi(i));
            found = true;
        }
    }
    sortAlpabetFront();
    //printed in ui
}
People Core::getList() const
{
    return list;
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

People Core::searchGend(const char ansGender)
{
    char findGender;
    People result;
   //  cout << "hello";
     cout << list.getSize();
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
