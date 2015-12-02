#include "people.h"

People::People() {

}

People::People(const string filename)
{
    ifstream ins;
    ins.open(filename.c_str());
    if(ins.fail())
    {
        cout << "Something went wrong while opening the file" << endl;
        exit(1);
    }
    string first ,last;
    int byear, dyear;
    char gender;
    while(getline(ins,last))
    {
        if(last == "\0")
        {
            getline(ins,last);
        }
        getline(ins,first);
        ins >> gender;
        ins >> byear;
        ins >> dyear;
        Individual i1(last,first,gender,byear,dyear);
        person.push_back(i1);
    }
    ins.close();
}

People::People(const People& p1)
{
    for(unsigned int i = 0 ; i < p1.person.size(); i++) {
       person.push_back(p1.person[i]);
    }
}

int People::getSize() const
{
    return(person.size());
}

void People::addIndi(Individual& i1)
{
    bool CheckIfNewIndi = true;
    for(unsigned int i = 0 ; i < person.size(); i++) {
        if(person[i]==i1)
            CheckIfNewIndi=false;
    }
    if(CheckIfNewIndi) {
        person.push_back(i1);
        saveFile(FILENAME);
    }
    else
        cout << "This person is already in the database " << endl;
}

Individual People::getIndi(const int i) const
{
    return person[i];
}

void People::saveFile(const string filename)
{
    ofstream outs;
    outs.open(filename.c_str(), ios::app);
    if(outs.fail())
    {
        cout << "Something went wrong with opening the output file" << endl;
        exit(1);
    }
    outs << endl;
    outs << person[person.size()-1].getSurname() << endl;
    outs << person[person.size()-1].getName() << endl;
    outs << person[person.size()-1].getGender() << endl;
    outs << person[person.size()-1].getBirth() << endl;
    outs << person[person.size()-1].getDeath() ;

    outs.close();
}

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
    for(unsigned int j = 0; j<r1.person.size(); j++) {
        if(r1.getIndi(j).getGender() == 'm' || r1.getIndi(j).getGender()=='M')
            male.person.push_back(r1.person[j]);
        else
            female.person.push_back(r1.person[j]);
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

void People::swap(const int i, const int j)
{
    Individual temp = person[i];
    person[i] = person[j];
    person[j] = temp;
}

void People::printVector()
{
     for(unsigned int i = 0; i < person.size(); i++) {
        cout << person[i] << endl;
     }
}

bool People::checkIndiOrder(const Individual& i1, const Individual& i2)
{
    string s1 = i1.getSurname();
    string s2 = i2.getSurname();
    char c1 = tolower(s1[0]);
    char c2 = tolower(s2[0]);
    int t1 = static_cast <int> (c1);
    int t2 = static_cast <int> (c2);
    if(t1==t2)
    {
        c1 = tolower(s1[1]);
        c2 = tolower(s2[1]);
        t1 = static_cast <int> (c1);
        t2 = static_cast <int> (c2);
        if(t1==t2)
        {
            c1 = tolower(s1[2]);
            c2 = tolower(s2[2]);
            t1 = static_cast <int> (c1);
            t2 = static_cast <int> (c2);
        }
    }

    return(t2>t1);
}

bool People::checkBirthYearOrder(const Individual& i1, const Individual& i2)
{
    return(i1.getBirth()>i2.getBirth());
}

bool People::checkDeathYearOrder(const Individual& i1, const Individual& i2)
{
    return(i1.getDeath()>i2.getDeath());
}

string People::makeLower(string& temp)
{
    for (unsigned int i = 0; i < temp.length(); i++) {
        if(isupper(temp[i]))
            temp[i] = tolower(temp[i]);
    }
    return temp;
}

void People::searchName()
{
    bool found = false;
    string tempStr, searchStr = "";
    cin.ignore();   //annars virkar getline ekki
    cout << "Enter a name to search for: " ;
    getline(cin, searchStr);
    searchStr = makeLower(searchStr);

    cout << "--- The following people match your search ---" << endl;
    for(unsigned int i = 0; i < person.size(); i++) {
        tempStr = person[i].getName() + " " + person[i].getSurname();
        tempStr = makeLower(tempStr);
        if(tempStr.find(searchStr) != string::npos) {  //if ( . == string::npos) ->not found
            cout << person[i] << endl;
            found = true;
        }
    }
    if (found == false)
        cout << "No one matched your search." << endl;
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
            if (tolower(ansGender) == tolower(findGender)) {
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
        for (unsigned int i = 0; i < person.size(); i++) {
            findYear = person[i].getBirth();
            if (ansYear == findYear) {
                result1.person.push_back(person[i]);
                found = true;
            }
            if (ansYear - 5 <= findYear && ansYear+5 >= findYear) {
                result2.person.push_back(person[i]);
            }
        }
        if(found) {
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
        for (unsigned int i = 0; i < person.size(); i++) {
            findYear = person[i].getDeath();
            if (ansYear == findYear)
            {
                result1.person.push_back(person[i]);
                found = true;
            }
            if (ansYear - 5 <= findYear && ansYear + 5 >= findYear) {
                result2.person.push_back(person[i]);
            }
        }
        if(found) {
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

People People::removeIndi()
{
    People removed;
    char ans;
    string name, tempName;
    bool found = false;

    cout << endl << "Do you want to see the list of all people?(y/n) " << endl;
    cin >> ans;
    if (ans == 'y' || ans == 'Y')
        printVector();
    cin.ignore();

    cout << "Enter the exact name of the individual that will be removed: ";
    getline(cin, name);     // input as: name surname

    for (unsigned int i = 0; i < person.size(); i++) {
        tempName = person[i].getName() + " " + person[i].getSurname();
        if(tempName != name) {
            removed.person.push_back(person[i]);
        }
        else if(tempName == name)
            found = true;
    }

    if (found == false) {
        cout << "There is no one named " << name << " on the list." << endl;
        return *this;
    }
    else {
        ofstream file;
        file.open(FILENAME.c_str());
        file << removed;
        file.close();
        cout << name <<" was successfully removed"<< endl;
        return removed;
    }
}

ostream& operator << (ostream& outs, People& p1)
{
    for(unsigned int i = 0; i<p1.person.size();i++)
    {
        outs << p1.person[i].getSurname() << endl;
        outs << p1.person[i].getName() << endl;
        outs << p1.person[i].getGender() << endl;
        outs << p1.person[i].getBirth() << endl;
        if(i == p1.person.size()-1)
            outs << p1.person[i].getDeath();
        else
            outs << p1.person[i].getDeath() << endl;
    }
    return outs;
}

