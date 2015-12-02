#include "core.h"

Core::Core()
{

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
}

void People::sortAlpabetBack()
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
}

void People::sortByBirthYear()
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

/*    Search functions:

void People::searchName()
{
    bool found = false;
    string tempStr, searchStr = "";
    cin.ignore();   //annars virkar getline ekki
    cout << "Enter a name to search for: " ;
    getline(cin, searchStr);
    searchStr = makeLower(searchStr);

    cout << "--- The following people match your search ---" << endl;
    for(unsigned int i = 0; i < person.size(); i++)
    {
        tempStr = person[i].getName() + " " + person[i].getSurname();
        tempStr = makeLower(tempStr);
        if(tempStr.find(searchStr) != string::npos)
        {
            cout << person[i] << endl;
            found = true;
        }
    }
    if (found == false)
    {
        cout << "No one matched your search." << endl;
    }
}

void People::searchGender()
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
        cout << "--- The following people match your search ---" << endl;
        for (unsigned int i = 0; i < person.size(); i++)
        {
            findGender = person[i].getGender();
            if (tolower(ansGender) == tolower(findGender))
            {
                result.person.push_back(person[i]);
                found = true;
            }
        }
        result.sortAlpabetFront();
    }
    else
    {
        cout << "Incorrect input, please try again!" << endl;
        this->searchGender();
    }
    if (found == false)
    {
        cout << "No one matched your search!" << endl;
    }
}

void People::searchBirth()
{
    People result1, result2;
    bool found = false;
    int findYear, ansYear;
    cout << "Enter a birth year: ";
    cin >> ansYear;
    if(!cin.fail())
    {
        cout << "--- The following people match your search ---" << endl;
        for (unsigned int i = 0; i < person.size(); i++)
        {
            findYear = person[i].getBirth();
            if (ansYear == findYear)
            {
                result1.person.push_back(person[i]);
                found = true;
            }
            if (ansYear - 5 <= findYear && ansYear+5 >= findYear)
            {
                result2.person.push_back(person[i]);
            }
        }
        if(found)
        {
            result1.sortAlpabetFront();
        }
        if (found == false)
        {
           cout << "No one matched your search." << endl;
                if(result2.person.size()!=0)
                {
                    cout << "However these individuals were found within"
                            " a 10 year range of given year: " << endl;
                    cout << "--- Printing by alphabetical order ---" << endl;
                    result2.sortAlpabetFront();
                }
        }
    }
    else
    {
        cout << "Incorrect input, please try again!" << endl;
        cin.clear();
        cin.ignore();
        this->searchBirth();
    }
}

void People::searchDeath()
{
    People result1, result2;
    bool found = false;
    int findYear, ansYear;
    cout << "Enter a death year: ";
    cin >> ansYear;
    if(!cin.fail())
    {
        cout << "--- The following people match your search ---" << endl;
        for (unsigned int i = 0; i < person.size(); i++)
        {
            findYear = person[i].getDeath();
            if (ansYear == findYear)
            {
                result1.person.push_back(person[i]);
                found = true;
            }
            if (ansYear - 5 <= findYear && ansYear + 5 >= findYear)
            {
                result2.person.push_back(person[i]);
            }
        }
        if(found)
        {
            result1.sortAlpabetFront();
        }
        if (found == false)
        {
           cout << "No one matched your search." << endl;
                if(result2.person.size()!=0)
                {
                    cout << "However these individuals were found within"
                            " a 10 year range of given year: " << endl;
                    result2.sortAlpabetFront();
                }
        }
    }
    else
    {
        cout << "Incorrect input, please try again!" << endl;
        cin.clear();
        cin.ignore();
        this->searchDeath();

    }
}

*/
