#include "ui.h"

// á að gera if/for/while/switch/return(...)      ->án bils
// eða if (...)     ->með bili

UI::UI()
{

}

UI::UI(const string filename)
{
    core.createList(filename);
}

void UI::run()
{
    welcomeMessage();
    while(true)
    {
        char choice;
        choiceMenu();
        cin >> choice;
        choiceSwitch(choice);
    }
}

void UI::choiceMenu()
{
    cout << endl;
    cout << "(S) Work with scientist database " << endl
         << "(C) Work with computer database " << endl
         << "(L) Work with linking of databases" << endl
         << "(Q) Quit program"<< endl;
    cout << "Select a letter: ";
}

void UI::choiceSwitch(char ans)
{
    switch(ans) {
        case 's':
        case 'S':   sciMenu();
                    break;
        case 'c':
        case 'C':   comMenu();
                    break;
        case 'l':
        case 'L':   // linking databases
                    break;
        case 'q':
        case 'Q':   cout << endl;
                    exit(1);
                    break;
        default:    errorInput();
                    break;
    }
}

void UI::ask()
{
    cout << endl;
    cout << "Do you want to: " << endl;
    cout << "(A) Add to list? " << endl;
    cout << "(S) Search list? " << endl;
    cout << "(P) Print list? " << endl;
    cout << "(L) Print list size?" << endl;
    cout << "(R) Remove from list? " << endl;
    cout << "(M) Return to main menu? " << endl;
    cout << "(Q) Quit program. " << endl;
    cout << "Select a letter: ";
}

void UI::sciMenu()
{
    char ans;
    ask();
    cin >> ans;
    switch(ans) {
        case 'a':
        case 'A':   addIndividual();
                    break;
        case 's':
        case 'S':   searchSciMenu();
                    break;
        case 'p':
        case 'P':   sortSciMenu();
                    break;
        case 'l':
        case 'L':   cout << "The current size of this list is: " << core.getSizeOfList() << endl;
                    break;
        case 'r':
        case 'R':   removeSci();
                    break;
        case 'm':
        case 'M':   return;
                    break;
        case 'q':
        case 'Q':   cout << endl;
                    exit(1);
                    break;
        default:    errorInput();
                    break;
    }
}

void UI::comMenu()
{
    char ans;
    ask();
    cin >> ans;
    switch(ans) {
        case 'a':
        case 'A':   addComputer();
                    break;
        case 's':
        case 'S':   searchComMenu();
                    break;
        case 'p':
        case 'P':   sortComMenu();
                    break;
        case 'l':
        case 'L':   cout << "The current size of this list is: " << core.getSizeOfComplist() << endl;
                    break;     
        case 'r':
        case 'R':   removeCom();
                    break;
        case 'm':
        case 'M':   return;
                    break;
        case 'q':
        case 'Q':   cout << endl;
                    exit(1);
                    break;
        default:    errorInput();
                    break;
    }
}

void UI::searchComMenu()
{
    cout << endl;
    char choice;
    cout << "Search by: " << endl;
    cout << "(N) Name" << endl
         << "(T) Type" << endl
         << "(C) Year of Creation" << endl
         << "(Q) Quit program" <<endl
         << "(M) Return to Menu"<<endl;
    cout << "Select a letter: ";
    cin >> choice;
    switch(choice)
    {
        case 'n':
        case 'N':   //searchComName();
                    break;
        case 't':
        case 'T':   // searchType();
                    break;
        case 'c':
        case 'C':   // searchCreation();
                    break;
        case 'm':
        case 'M':   return;
                    break;
        case 'q':
        case 'Q':   // quit program
                    break;
        default:    errorInput();
                    searchComMenu();
                    break;
    }
    searchComMenu();
}

void UI::searchSciMenu()
{
    cout << endl;
    char choice;
    cout << "Search by: " << endl;
    cout << "(N) Name" << endl
         << "(G) Gender" << endl
         << "(B) Year of Birth" << endl
         << "(D) Year of Death" << endl
         << "(M) Return to Menu" << endl
         << "(Q) Quit program " << endl;
    cout << "Select a letter: ";
    cin >> choice;

    switch(choice) {
        case 'n':
        case 'N':   searchSciName();
                    break;
        case 'g':
        case 'G':   searchGender();
                    break;
        case 'b':
        case 'B':   searchBirth();
                    break;
        case 'd':
        case 'D':   searchDeath();
                    break;
        case 'M':
        case 'm':   return; //this->menu();
                    break;
        case 'q':
        case 'Q':   exit(1);
                    break;
        default:    errorInput();
                    searchSciMenu();
    }
    searchSciMenu();
}

void UI::sortComMenu()
{
    char choice;
    cout << endl;
    cout << "Print by: " << endl;
    cout << "(U) Unordered" << endl
         << "(A) Alphabetic order" << endl
         << "(R) Reverse alphabetic order" << endl
         << "(T) Type alphabetic order" << endl
         << "(C) Year of Creation" << endl
         << "(M) Return to Menu" << endl
         << "(Q) Quit program " << endl;
    cout << "Select a letter: ";
    cin >> choice;
    switch(choice) {
        case 'a':
        case 'A':   cout << endl << "--- Printing by alphabetical order --- " << endl;
                    // sort alpha front
                    //princom
                    break;
        case 'r':
        case 'R':   cout << endl << "--- Printing by reverse alphabetical order --- " << endl;
                    // sort reverse alpha
                    // printcom
                    break;
        case 'b':
        case 'B':   cout << endl << "--- Printing by year of Creation --- " << endl;
                    // sort creation year eftir ad utfæra
                    //printcom
                    break;
        case 't':
        case 'T':   cout<<endl<<"--- Printing by alphebetical type order ---"<<endl;
                    break;
        case 'm':
        case 'M':   return;
                    break;
        case 'q':
        case 'Q':   exit(1);
                    break;
        default:    errorInput();
                    sortSciMenu();
                    break;
    }
    sortSciMenu();
}

void UI::sortSciMenu()
{
    char choice;
    cout << endl;
    cout << "Print by: " << endl;
    cout << "(U) Unordered" << endl
         << "(A) Alphabetic order" << endl
         << "(R) Reverse alphabetic order" << endl
         << "(B) Year of Birth" << endl
         << "(D) Year of Death" << endl
         << "(M) Return to Menu" << endl
         << "(Q) Quit program " << endl;
    cout << "Select a letter: ";
    cin >> choice;

    switch(choice) {
        case 'u':
        case 'U':   print();
                    break;
        case 'a':
        case 'A':   cout << endl << "--- Printing by alphabetical order --- " << endl;
                    core.sortAlpabetFront();
                    print();
                    break;
        case 'r':
        case 'R':   cout << endl << "--- Printing by reverse alphabetical order --- " << endl;
                    core.sortAlpabetBack();
                    print();
                    break;
        case 'b':
        case 'B':   cout << endl << "--- Printing by year of Birth --- " << endl;
                    core.sortByBirthYear();
                    print();
                    break;
        case 'd':
        case 'D':   cout << endl << "--- Printing by year of Death --- " << endl;
                    core.sortByDeathYear();
                    print();
                    break;
        case 'M':
        case 'm':   return;
                    break;
        case 'q':
        case 'Q':   exit(1);
                    break;
        default:    errorInput();
                    sortSciMenu();
                    break;
    }
    sortSciMenu();
}

void UI::welcomeMessage()
{
    cout << "------------Welcome to the database of famous computer scientists-------------" << endl;
    cout << "\t" << "    In this database you can add, remove, sort and search" << endl;
    cout << "\t \t" << " At this moment we have "<< core.getList().getSize() << " computer scientists" << endl;
    cout << "\t \t \t" << " and "<< core.getComputers().getSize() << " computers" << endl;
    cout << "------------------------------------Enjoy!------------------------------------" << endl;
}

void UI::addIndividual()
{
    string surname, name;
    int birth, death;
    char gender;
    bool notfound = false;

    cin.ignore();
    cout << endl;
    char ans;
    cout << "Surname: ";
    getline(cin, surname);
    cout << "Given name: ";
    getline(cin, name);

    do{
        cout << "Gender (m/f): ";
        cin >> gender;
        if(gender != 'f' && gender != 'm' && gender != 'F' && gender != 'M')
        {
            errorInput();
        }
    } while(gender != 'f' && gender != 'm' && gender != 'F' && gender != 'M');

    do {
        cin.clear();
        cin.ignore();
        cout << "Year of birth: ";
        cin >> birth;
        if(cin.fail())
        {
            errorInput();
        }
    } while(cin.fail());

    cout << "Is the individual alive?(y/n) ";
    cin >> ans;
    if (ans == 'n' || ans == 'N')
    {
        do {
                cin.clear();
                cin.ignore();
                cout << "Year of death: ";
                cin >> death;
                if(cin.fail())
            {
                errorInput();
            }
            if(birth > death)
            {
                cout << "Illegal deathyear! Input again: " << endl << endl;   //errorInput(); ?
            }
        } while(cin.fail() || birth > death);
    }
    else
    {
        death = 0;
    }
    Individual temp(surname, name, gender, birth, death); //fer inn i add
    core.addIndividual(temp,notfound);
    if(!notfound)
    {
        cout << endl;
        cout << "This Individual is already in the database! " << endl;
    }
}

void UI::printIndi(int i) const
{
    Individual temp = core.getList().getIndi(i);
    cout << endl;
    cout << "Name: " << temp.getName() << " " << temp.getSurname() << endl;
    cout << "Gender: ";
    if(temp.getGender() == 'f' || temp.getGender() == 'F')
    {
        cout << "Female" << endl;
    }
    else
    {
        cout << "Male" << endl;
    }
    cout << temp.getBirth() << " - ";
    if(temp.getDeath() == 0)
    {
        cout << "Today";
    }
    else
    {
        cout << temp.getDeath();
    }
    cout << endl;
}

void UI::printList() const
{
    for(int i = 0; i < core.getSizeOfList(); i++)
    {
        printIndi(i);
    }
}

void UI::printList(People& list) const
{
    for (int i = 0; i < list.getSize(); i++)
    {
        Individual id = list.getIndi(i);
        printIndi(id);
    }
}

void UI::printIndi(Individual& temp) const
{
    cout << endl;
    cout << "Name: " << temp.getName() << " " << temp.getSurname() << endl;
    cout << "Gender: ";
    if(temp.getGender() == 'f' || temp.getGender() == 'F')
    {
        cout << "Female" << endl;
    }
    else
    {
        cout << "Male" << endl;
    }
    cout << temp.getBirth() << " - ";
    if(temp.getDeath() == 0)
    {
        cout << "Today";
    }
    else
    {
        cout << temp.getDeath();
    }
    cout << endl;
}

void UI::removeCom()
{
    string str;
    bool removed = false;
    cin.ignore();
    cout << endl;
    cout << "Type exactly the name of the computer:" << endl;
    getline(cin, str);
    core.removeComputer(str, removed);
    if (removed)
    {
        cout << str << " has been removed." << endl;
    }
    else if (!removed)
    {
        cout << str << " was not found in list and therefore not removed." << endl;
    }
}

void UI::removeSci()
{
    string str;
    bool removed = false;
    cin.ignore();
    cout << endl;
    cout << "Type exactly the name of the individual:" << endl;
    getline(cin, str);
    core.removeIndividual(str, removed);
    if (removed)
    {
        cout << str << " has been removed." << endl;
    }
    else if (!removed)
    {
        cout << str << " was not found in list and therefore not removed." << endl;
    }
}

void UI::searchComYear()
{
    Computer result1, result2;
    bool found = false;
    int ansYear;
    cout << "Enter year of creation: ";
    cin >> ansYear;
    if(!cin.fail())
    {
       // People result = core.searchBir(found, ansYear, result1, result2);
        if(found)
        {
         //   individualsMatched();
         //   printList(result);
        }
        else if (!found)
        {
            cout << endl;
            // noMatch();
            //  if(result2.getSize() != 0)
            {
                cout << "However these computers were found within"
                        " a 10 year range of given year: " << endl;
                // printList(result);
            }
        }
    }
    else
    {
        errorInput();
        cin.clear();
        cin.ignore();
        searchComYear();
    }
}

void UI::searchComName()
{
    Computer result;
    bool found = false;
    string searchStr;
    cin.ignore();
    cout << "Enter a name to search for: " ;
    getline(cin, searchStr);
    //  result = core.searchComName(found, searchStr, result);

    if (found)
    {
       // individualsMatched();
       // printList(result);
    }
    if (!found)
    {
      //  noMatch();
    }
}

void UI::searchSciName()
{
    People result;
    bool found = false;
    string searchStr;
    cin.ignore();
    cout << "Enter a name to search for: " ;
    getline(cin, searchStr);

    result = core.searchNam(found, searchStr, result);

    if (found)
    {
        individualsMatched();
        printList(result);
    }
    if (!found)
    {
        noMatch();
    }
}

void UI::searchComType()
{
    People result;
    bool found = false;
    string searchStr;
    cin.ignore();
    cout << "Enter a type to search for: " ;
    getline(cin, searchStr);

   // result = core.searchNam(found, searchStr, result);

    if (found)
    {
        //individualsMatched();
        //printList(result);
    }
    if (!found)
    {
        //noMatch(); //þarf að vera fyrir tölvur
    }
}
void UI::searchGender()
{
    People result;
    char ansGender;
    cout << endl;
    cout << "Enter which gender you want to search for (m/f): ";
    cin >> ansGender;
    cout << endl;
    if(ansGender == 'm' || ansGender == 'M' || ansGender == 'f' || ansGender == 'F')
    {
        individualsMatched();
        Core c1(core.searchGend(ansGender));
        c1.sortAlpabetFront();
        if(c1.getList().getSize()!=0)
        {
            People p1 = c1.getList();
            printList(p1);
        }
        else
        {
            this->noMatch();
        }
    }
    else
    {
        errorInput();
        searchGender();
    }
}

void UI::searchBirth()
{
    People result1, result2;
    bool found = false;
    int ansYear;
    cout << "Enter a birth year: ";
    cin >> ansYear;
    if(!cin.fail())
    {
        People result = core.searchBir(found, ansYear, result1, result2);
        if(found)
        {
            individualsMatched();
            printList(result);
        }
        else if (!found)
        {
            cout << endl;
            noMatch();
            if(result2.getSize() != 0)
            {
                cout << "However these individuals were found within"
                        " a 10 year range of given year: " << endl;
                printList(result);
            }
        }
    }
    else
    {
        errorInput();
        cin.clear();
        cin.ignore();
        searchBirth();
    }
}

void UI::searchDeath()
{
    People result1, result2;
    bool found = false;
    int ansYear;
    cout << "Enter a death year: ";
    cin >> ansYear;
    if(!cin.fail())
    {
        People result = core.searchDea(found, ansYear, result1, result2);
        if(found)
        {
            individualsMatched();
            printList(result);
        }
        else if (!found)
        {
            cout << endl;
            noMatch();
            if(result2.getSize() != 0)
            {
                cout << "However these individuals were found within"
                        " a 10 year range of given year: " << endl;
                printList(result);
            }
        }
    }
    else
    {
        errorInput();
        cin.clear();
        cin.ignore();
        searchDeath();
    }
}

void UI::print()
{
    cout << endl;
    for(int i = 0; i < core.getList().getSize(); i++)
    {
        cout << "Name: " << core.getSurname(i) + ", " + core.getName(i) << endl;
        cout << "Gender: ";
        if(core.getGender(i) == 'm' || core.getGender(i) == 'M')
        {
            cout << "Male" << endl;
        }
        else
        {
            cout << "Female" << endl;
        }
        cout << core.getBirth(i) << " - ";
        if(core.getDeath(i) == 0)
        {
            cout << "Today" << endl;
        }
        else
        {
            cout << core.getDeath(i)<<endl;
        }
        cout << endl;
    }
}

void UI::addComputer(){
    string name, type;
    int year;
    char ans;
    cin.ignore();
    cout << endl;
    cout << "Name: ";
    getline(cin, name);
    cout << "Type: ";
    getline(cin, type);

    cout << "Was the computer created(y/n)?";
    cin >> ans;

    if(ans == 'y'|| ans =='Y')
    {
        cout << "Creation year: ";
        cin >> year;
    }
    else
    {
        year = 0;
    }
}

void UI::printComputer()
{
    cout << endl;
    for(int i = 0; i < core.getList().getSize(); i++)
    {
        cout << "Name: " << core.getCompname(i) << endl;
        cout << "Type: " << core.getComptype(i) << endl;
        if(core.getYear(i) != 0)
        {
            cout << "Creation year: " << core.getYear(i);
        }
        else
        {
            cout << "The computer was not created " << endl;
        }
    }
}

void UI::printSize()
{
    cout << core.getSizeOfList();
}

void UI::errorFile()
{
    cout << "Something went wrong while opening the file" << endl;
}

void UI::errorInput()
{
    cout << "Invalid input, try again." << endl;
}

void UI::individualsMatched()
{
    cout << endl << "--- The following entries match your search ---" << endl;
}

void UI::noMatch()
{
    cout << "No one matched your search." << endl;
}

void UI::inDatabase()
{
    cout << "This instance is already in the database " << endl;
}

void UI::readingString(string gender)
{
    cout << "--- Reading " << gender << " ---" << endl;
}
