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
    switch(ans)
    {
        case 's':
        case 'S':   sciMenu();
                    break;
        case 'c':
        case 'C':   comMenu();
                    break;
        case 'l':
        case 'L':   linkMenu();
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
    switch(ans)
    {
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
        case 'L':   cout << "The current size of the scientist list is: "
                         << core.getSizeOfList() << endl;
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
    sciMenu();
}

void UI::comMenu()
{
    char ans;
    ask();
    cin >> ans;
    switch(ans)
    {
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
        case 'L':   cout << "The current size of the computer list is: "
                         << core.getSizeOfComplist() << endl;
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
    comMenu();
}

void UI::linkMenu()
{   cout<<endl;
    cout << "Do you want to: " << endl;
    cout << "(A) Add a connection? " << endl;
    cout << "(P) Print connections? " << endl;
    cout << "(R) Remove a connection? " << endl;
    cout << "(M) Return to main menu? " << endl;
    cout << "(Q) Quit program. " << endl;
    cout << "Select a letter: ";
    char ans;
    cin >> ans;
    switch(ans)
    {
        case 'a':
        case 'A':
                    break;
        case 'p':
        case 'P':
                    break;
        case 'r':
        case 'R':
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
    linkMenu();
}

void UI::searchComMenu()
{
    cout << endl;
    char choice;
    cout << "Search by: " << endl;
    cout << "(N) Name" << endl
         << "(T) Type" << endl
         << "(C) Year of Creation" << endl
         << "(M) Return to Menu" << endl
         << "(Q) Quit program" << endl;
    cout << "Select a letter: ";
    cin >> choice;
    switch(choice)
    {
        case 'n':
        case 'N':   searchComName();
                    break;
        case 't':
        case 'T':   searchComType();
                    break;
        case 'c':
        case 'C':   searchComYear();
                    break;
        case 'm':
        case 'M':   return;
                    break;
        case 'q':
        case 'Q':   cout << endl;
                    exit(1);
                    break;
        default:    errorInput();
                    searchComMenu();
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

    switch(choice)
    {
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
        case 'm':   return;
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
    switch(choice)
    {
        case 'a':
        case 'A':   cout << endl << "--- Printing by alphabetical order --- " << endl;
                    {
                    Machines temp = core.sortCompAlpabetFront();
                    printComputers(temp);
                    }
                    break;
        case 'r':
        case 'R':   cout << endl << "--- Printing by reverse alphabetical order --- " << endl;
                    {
                    Machines temp = core.sortCompAlpabetBack();
                    printComputers(temp);
                    }
                    break;
        case 'c':
        case 'C':   cout << endl << "--- Printing by year of Creation --- " << endl;
                    {
                    Machines temp = core.sortCompBuildYear();
                    printComputers(temp);
                    }
                    break;
        case 't':
        case 'T':   cout << endl << "--- Printing by alphebetical type order ---" << endl;
                    {
                    Machines temp = core.sortCompType();
                    printComputers(temp);
                    }
                    break;
        case 'm':
        case 'M':   return;
                    break;
        case 'q':
        case 'Q':   cout << endl;
                    exit(1);
                    break;
        default:    errorInput();
                    sortSciMenu();
                    break;
    }
    sortComMenu();
}

void UI::sortSciMenu()
{
    char choice;
    cout << endl;
    cout << "Print by: " << endl;
    cout << "(A) Alphabetic order" << endl
         << "(R) Reverse alphabetic order" << endl
         << "(B) Year of Birth" << endl
         << "(D) Year of Death" << endl
         << "(M) Return to Menu" << endl
         << "(Q) Quit program " << endl;
    cout << "Select a letter: ";
    cin >> choice;

    switch(choice)
    {
        case 'a':
        case 'A':   cout << endl << "--- Printing by alphabetical order --- " << endl;
                    {
                    People temp = core.sortSciAlpabetFront();
                    printScientists(temp);
                    }
                    break;
        case 'r':
        case 'R':   cout << endl << "--- Printing by reverse alphabetical order --- " << endl;

                    {
                    People temp = core.sortSciAlpabetBack();
                    printScientists(temp);
                    }
                    break;
        case 'b':
        case 'B':   cout << endl << "--- Printing by year of Birth --- " << endl;
                    {
                    People temp = core.sortSciByBirthYear();
                    printScientists(temp);
                    }
                    break;
        case 'd':
        case 'D':   cout << endl << "--- Printing by year of Death --- " << endl;
                    {
                    People temp = core.sortSciByDeathYear();
                    printScientists(temp);
                    }
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
    cout << "--- Welcome to the databases of famous computer scientists and of computers ---" << endl;
    cout << "\t" << "    In these databases you can add, remove, sort and search" << endl;
    cout << "\t \t" << " At this moment we have "<< core.getPeopleSizeInNewdata() << " computer scientists" << endl;
    cout << "\t \t \t " << "      and "<< core.getMachineSizeInNewdata() << " computers" << endl;
    cout << "------------------------------------Enjoy!------------------------------------" << endl;
}

void UI::searchComYear()
{
    Machines result1, result2;
    bool found = false;
    int ansYear;
    cout << "Enter year of creation: ";
    cin >> ansYear;
    if(!cin.fail())
    {
        Machines result = core.searchComYear(found, ansYear, result1, result2);
        if(found)
        {
            entriesMatched();
            printComplist(result);
        }
        else if (!found)
        {
            cout << endl;
            noMatch();
            if(result.getSize() != 0)
            {
                cout << "However these computers were found within"
                        " a 10 year range of given year: " << endl;
                printComplist(result);
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
    Machines result;
    string searchStr;
    cin.ignore();
    cout << "Enter a name to search for: " ;
    getline(cin, searchStr);

    result = core.searchComName(searchStr, result);

    if (result.getSize() != 0)
    {
        entriesMatched();
        printComplist(result);
    }
    else
    {
        noMatch();
    }
}

void UI::searchComType()
{
    Machines result;
    string searchStr;
    cin.ignore();
    cout << "Enter a type to search for: " ;
    getline(cin, searchStr);

    result = core.searchComType(searchStr, result);

    if (result.getSize() != 0)
    {
        entriesMatched();
        printComplist(result);
    }
    else
    {
        noMatch();
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

    if (result.getSize() != 0) //þá taka út bool found
    {
        entriesMatched();
        printList(result);
    }
    else
    {
        noMatch();
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
        result = core.searchGend(ansGender);
        if(result.getSize() != 0)
        {
            entriesMatched();
            printList(result);
        }
        else
        {
            noMatch();
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
            entriesMatched();
            printList(result);
        }
        else if (!found)
        {
            cout << endl;
            noMatch();
            if(result.getSize() != 0)
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
            entriesMatched();
            printList(result);
        }
        else if (!found)
        {
            cout << endl;
            noMatch();
            if(result.getSize() != 0)
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
                cout << "Illegal deathyear! Input again: " << endl << endl;
            }
        } while(cin.fail() || birth > death);
    }
    else
    {
        death = 0;
    }
    Individual temp(surname, name, gender, birth, death);
    core.addIndividual(temp, notfound);
    if(!notfound)
    {
        cout << endl;
        cout << "This Individual is already in the database! " << endl;
    }
}

void UI::addComputer()
{
    string name, type;
    int year;
    char ans;
    bool notfound = false;
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

    Computer temp(year, name, type);
    core.addComputer(temp, notfound);
    if(!notfound)
    {
        cout << endl;
        cout << "This Computer is already in the database! " << endl;
    }
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

void UI::printScientists(People& sci)
{
    cout << endl;

    for(int i = 0; i < sci.getSize(); i++)
    {
        Individual temp = sci.getIndi(i);
        //printIndi(temp);
        printIndiAndConnect(temp);

        /*cout << "Name: " << core.getSurname(i) + ", " + core.getName(i) << endl;
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
            cout << core.getDeath(i) << endl;
        }*/
    }

    cout << endl;
}

void UI::printComputers(Machines &comps)
{
    cout << endl;
    for(int i = 0; i < comps.getSize(); i++)
    {
        Computer temp = comps.getComputer(i);
        printComp(temp);
    }


/*    for(int i = 0; i < core.getList().getSize(); i++)
    {
        cout << "Name: " << core.getCompname(i) << endl;
        cout << "Type: " << core.getComptype(i) << endl;
        if(core.getYear(i) != 0)
        {
            cout << "Year of creation: " << core.getYear(i) << endl;
        }
        else
        {
            cout << "The computer was not built." << endl;
        }
    }*/
}

void UI::printIndiIndent(Individual &id) const
{
    cout << endl;
    cout << "/t" << id.getName() << " " << id.getSurname() << "/t";

    if(id.getGender() == 'f' || id.getGender() == 'F')
    {
        cout << "Female";
    }
    else
    {
        cout << "Male";
    }

    cout << "/t" << id.getBirth() << " - ";

    if(id.getDeath() == 0)
    {
        cout << "Today";
    }
    else
    {
        cout << id.getDeath();
    }
    cout << endl;

}

void UI::printCompIndent(Computer &id) const
{
    cout << endl;
    cout << "\t" << id.getName() << "\t" << id.getType() << "\t";

    if(id.getYear() == 0)
    {
        cout << "Unbuilt";
    }
    else
    {
        cout << id.getYear();
    }
    cout << endl;

}

void UI::printConnectedComp(Machines& comps) const
{
    for(int i = 0; i < comps.getSize(); i++)
    {
        Computer temp = comps.getComputer(i);
        printCompIndent(temp);
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
        cout << "Today" << endl;
    }
    else
    {
        cout << temp.getDeath() << endl;
    }
}

void UI::printIndiAndConnect(Individual & sci)
{
    printIndi(sci);
    int id = sci.getId();
    Machines temp = core.getConnectedComp(id);
    printConnectedComp(temp);
}

void UI::printComplist(Machines& complist) const
{
    for (int i = 0; i < complist.getSize(); i++)
    {
        Computer com = complist.getComputer(i);
        printComp(com);
    }
}

void UI::printComp(Computer& temp) const
{
    cout << endl;
    cout << "Name: " << temp.getName() << endl;
    cout << "Type: " << temp.getType() << endl;
    if (temp.getYear() != 0)
    {
        cout << "Year of creation: " << temp.getYear() << endl;
    }
    else
    {
        cout << "This computer was not built." << endl;
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

void UI::entriesMatched()
{
    cout << endl << "--- The following database entries match your search ---" << endl;
}

void UI::noMatch()
{
    cout << "No database entries matched your search." << endl;
}

void UI::inDatabase()
{
    cout << "This instance is already in the database " << endl;
}

void UI::readingString(string gender)
{
    cout << "--- Reading " << gender << " ---" << endl;
}
