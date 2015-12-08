#include "ui.h"

UI::UI()
{

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
    cout << "(S) Work with scientist database." << endl
         << "(C) Work with computer database." << endl
         << "(L) Work with linking of databases." << endl
         << "(Q) Quit program."<< endl;
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
    cout << "What do you want to do?" << endl;
    cout << "(A) Add to list." << endl;
    cout << "(S) Search list." << endl;
    cout << "(P) Print list." << endl;
    cout << "(R) Remove from list." << endl;
    cout << "(C) Change information."<<endl;
    cout << "(M) Return to main menu." << endl;
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
                         << core.getPeopleSizeInNewdata() << endl;
                    break;
        case 'c':
        case 'C':   updateSciMenu();
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
                         << core.getMachineSizeInNewdata() << endl;
                    break;
        case 'r':
        case 'R':   removeCom();
                    break;
        case 'c':
        case 'C':   updateCompMenu();
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
void UI::searchLinkMenu()
{
    clearScreen();
    cout << "What do you want to do?" << endl;
    cout << "(S) Search for a scientist and return computers he is connected to." << endl;
    cout << "(C) Search for a computer and return scientists he is connected to." << endl;
    cout << "(M) Return to menu." << endl;
    cout << "(Q) Quit program. " << endl;
    cout << "Select a letter: ";
    char ans;
    cin >>ans;

    switch(ans)
    {
          case 's':
          case 'S': searchSciLink();
                    break;
          case 'c':
          case 'C': searchComLink();
                    break;
          case 'm':
          case 'M': return;
                    break;
          case 'q':
          case 'Q': cout << endl;
                    exit(1);
                    break;
          default:  errorInput();
                    break;
    }
}

void UI::printLinkMenu()
{
    clearScreen();
    cout << "What do you want to do?" << endl;
    cout << "(S) Print scientists and computers connected to them?" << endl;
    cout << "(C) Print computers and scientists connected to them? " << endl;
    cout << "(M) Return to menu? " << endl;
    cout << "(Q) Quit program. " << endl;
    cout << "Select a letter: ";
    char ans;
    cin >> ans;

    switch(ans)
    {
          case 's':
          case 'S': sortSciLink();
                    break;
          case 'c':
          case 'C': sortComLink();
                    break;
          case 'm':
          case 'M': return;
                    break;
          case 'q':
          case 'Q': cout << endl;
                    exit(1);
                    break;
          default:  errorInput();
                    break;
    }
}


void UI::linkMenu()
{
    cout << "What do you want to do?" << endl;
    cout << "(S) Search connections."<<endl;
    cout << "(A) Add a connection." << endl;
    cout << "(P) Print connections." << endl;
    cout << "(R) Remove a connection." << endl;
    cout << "(M) Return to main menu." << endl;
    cout << "(Q) Quit program." << endl;
    cout << "Select a letter: ";
    char ans;
    cin >> ans;

    switch(ans)
    {
        case 's':
        case 'S':   searchLinkMenu();
                    break;
        case 'a':
        case 'A':   addConnection();
                    break;
        case 'p':
        case 'P':   printLinkMenu();
                    break;
        case 'r':
        case 'R':   removeConnection();
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
    clearScreen();
    cout << endl;
    char choice;
    cout << "Search by: " << endl;
    cout << "(N) Name." << endl
         << "(T) Type." << endl
         << "(C) Year of Creation." << endl
         << "(Q) Quit program." <<endl
         << "(M) Return to Menu."<<endl;
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
}

void UI::searchSciMenu()
{
    clearScreen();
    cout << endl;
    char choice;
    cout << "Search by: " << endl;
    cout << "(N) Name." << endl
         << "(G) Gender." << endl
         << "(B) Year of Birth." << endl
         << "(D) Year of Death." << endl
         << "(M) Return to Menu." << endl
         << "(Q) Quit program." << endl;
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
        case 'm':
        case 'M':   return;
                    break;
        case 'q':
        case 'Q':   exit(1);
                    break;
        default:    errorInput();
                    searchSciMenu();
    }
}


void UI::sortComMenu()
{
    clearScreen();
    char choice;
    cout << "Print by: " << endl;
    cout << "(A) Alphabetic order." << endl
         << "(R) Reverse alphabetic order." << endl
         << "(T) Type alphabetic order." << endl
         << "(C) Year of Creation." << endl
         << "(M) Return to Menu." << endl
         << "(Q) Quit program." << endl;
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
}

void UI::sortSciMenu()
{
    clearScreen();
    char choice;
    cout << "Print by: " << endl;
    cout << "(A) Alphabetic order." << endl
         << "(R) Reverse alphabetic order." << endl
         << "(B) Year of Birth." << endl
         << "(D) Year of Death." << endl
         << "(M) Return to Menu." << endl
         << "(Q) Quit program." << endl;
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
}

void UI::updateSciMenu()
{
    int id, count;
    bool found = false;
    cout << "Please enter the id of the Scientist you want to change: ";
    cin >> id;
    cout << endl;
    if(!cin.fail())
    {
        People p1 = core.getData().sortIndiAlphaFront();
        for(int i = 0 ; i <p1.getSize(); i++)
        {
            if(id == p1.getIndi(i).getId())
            {
                found = true;
            }
        }
        if(found)
        {
            do
            {
                char choice;
                count = 0;
                cout << "What do you want to change?" << endl;
                cout << "(N)Name." << endl;
                cout << "(S)Surname." << endl;
                cout << "(B)Year of birth." << endl;
                cout << "(D)Year of death." << endl;
                cout << "(G)Gender." << endl;
                cout << "(M)Return to Menu." << endl;
                cout << "Select a letter: ";
                cin >> choice;
                cout << endl;
                switch(choice)
                {
                    case 'n':
                    case 'N':   updateIndiName(id);
                                break;
                    case 's':
                    case 'S':   updateIndiSurname(id);
                                break;
                    case 'b':
                    case 'B':   updateIndiBYear(id);
                                break;
                    case 'd':
                    case 'D':   updateIndiDYear(id);
                                break;
                    case 'g':
                    case 'G':   updateIndiGender(id);
                                break;
                    case 'm':
                    case 'M':   return;
                                break;

                    default:    count = -1;
                                errorInput();
                                updateSciMenu();
                                break;
                }
             } while(count == -1);
        }
        else
        {
            cout << "No scientist has this id!" << endl;
            cin.clear();
            cin.ignore();
            updateSciMenu();
        }
   }
   else
   {
        errorInput();
        cin.clear();
        cin.ignore();
        updateSciMenu();
   }

}

void UI::updateIndiName(const int id)
{
    string name;
    char ans;
    cout << "Please insert a new name: ";
    cin.ignore();
    getline(cin, name);
    Individual i1 = core.getData().getSingleIndi(id);
    string oldname = i1.getSurname();
    cout << "Do you want to change Scientist" << endl;
    cout << "From:" << endl;
    printIndi(i1);
    core.updateIndiName(name,id);
    cout << endl;
    cout << "To:" << endl;
    i1 = core.getData().getSingleIndi(id);
    printIndi(i1);
    cout << "Select letter(y/n): ";
    cin >> ans;
    while(cin.fail() || (ans!='y' && ans!='n'))
    {
        cin.clear();
        cin.ignore();
        cout << "Select letter(y/n): ";
        cin >> ans;
        if(cin.fail() || (ans!='y' && ans!='n'))
        {
            errorInput();
        }
    }
    if(ans == 'n')
    {
        core.updateIndiSurname(oldname,id);
        cout << endl;
        cout << "No changes were made!" << endl;
    }
    else if(ans == 'y')
    {
        cout << endl;
         cout << "Update succecfull!" << endl;
    }
}

void UI::updateIndiSurname(const int id)
{
    string surname;
    char ans;
    cout << "Please insert a new surname: ";
    cin.ignore();
    getline(cin, surname);
    Individual i1 = core.getData().getSingleIndi(id);
    string oldname = i1.getSurname();
    cout << "Do you want to change Scientist" << endl;
    cout << "From:" << endl;
    printIndi(i1);
    core.updateIndiSurname(surname,id);
    cout << endl;
    cout << "To:" << endl;
    i1 = core.getData().getSingleIndi(id);
    printIndi(i1);
    cout << "Select letter(y/n): ";
    cin >> ans;
    while(cin.fail() || (ans!='y' && ans!='n'))
    {
        cin.clear();
        cin.ignore();
        cout << "Select letter(y/n): ";
        cin >> ans;
        if(cin.fail() || (ans!='y' && ans!='n'))
        {
            errorInput();
        }
    }
    if(ans == 'n')
    {
        core.updateIndiName(oldname,id);
        cout << endl;
        cout << "No changes were made!" << endl;
    }
    else if(ans == 'y')
    {
        cout << endl;
         cout << "Update succecfull!" << endl;
    }
}

void UI::updateIndiGender(const int id)
{
    Individual i1 = core.getData().getSingleIndi(id);
    if(i1.getGender() == 'm')
    {

        core.updateIndiGender('f', id);
        cout << "--- Changing the scientist from male to female ---" << endl;
    }
    else
    {
        core.updateIndiGender('m', id);
        cout << "--- Changing the scientist from female to male ---" << endl;
    }
    i1 = core.getData().getSingleIndi(id);
    cout << "The scientist is now registered as:" << endl;
    printIndi(i1);
}

void UI::updateIndiBYear(const int id)
{
    int year;
    char ans;
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Insert a new birth year: ";
        cin >> year;
        if(cin.fail())
        {
            errorInput();
        }    
    } while(cin.fail());

    Individual i1 = core.getData().getSingleIndi(id);
    if(i1.getDeath() > year)
    {
        int old = i1.getBirth();
        cout << "Do you want to change Scientist" << endl;
        cout << "From:" << endl;
        printIndi(i1);
        core.updateIndiBYear(year,id);
        cout << endl;
        cout << "To:" << endl;
        i1 = core.getData().getSingleIndi(id);
        printIndi(i1);
        cout << "Select letter(y/n): ";
        cin >> ans;
        while(cin.fail() || (ans!='y' && ans!='n'))
        {
            cin.clear();
            cin.ignore();
            cout << "Select letter(y/n): ";
            cin >> ans;
            if(cin.fail() || (ans!='y' && ans!='n'))
            {
                errorInput();
            }
        }
        if(ans == 'n')
        {
            core.updateIndiBYear(old,id);
            cout << endl;
            cout << "No changes were made!" << endl;
        }
        else if(ans == 'y')
        {
            cout << endl;
             cout << "Update succecfull!" << endl;
        }
    }
    else
    {
        errorInput();
        updateIndiBYear(id);
    }
}

void UI::updateIndiDYear(const int id)
{
    int year;
    char ans;
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Insert a new year of death: ";
        cin >> year;
        if(cin.fail())
        {
            errorInput();
        }
    } while(cin.fail());

    Individual i1 = core.getData().getSingleIndi(id);
    if(i1.getBirth() < year)
    {
        int old = i1.getDeath();
        cout << "Do you want to change Scientist" << endl;
        cout << "From:" << endl;
        printIndi(i1);
        core.updateIndiDYear(year,id);
        cout << endl;
        cout << "To:" << endl;
        i1 = core.getData().getSingleIndi(id);
        printIndi(i1);
        cout << "Select letter(y/n): ";
        cin >> ans;
        while(cin.fail() || (ans!='y' && ans!='n'))
        {
            cin.clear();
            cin.ignore();
            cout << "Select letter(y/n): ";
            cin >> ans;
            if(cin.fail() || (ans!='y' && ans!='n'))
            {
                errorInput();
            }
        }
        if(ans == 'n')
        {
            core.updateIndiDYear(old,id);
            cout << endl;
            cout << "No changes were made!" << endl;
        }
        else if(ans == 'y')
        {
            cout << endl;
             cout << "Update succecfull!" << endl;
        }
    }
    else
    {
        errorInput();
        updateIndiBYear(id);
    }
}

void UI::updateCompMenu()
{
        int id, count;
        bool found=false;
        cout << "Please enter the id of the Computer you want to change: ";
        cin >> id;
        cout << endl;
        if(!cin.fail())
        {
            Machines c1 = core.getData().sortCompAlphaFront();
            for(int i = 0 ; i < c1.getSize(); i++)
            {
                if(id == c1.getComputer(i).getId())
                {
                    found = true;
                }
            }

            if(found)
            {
                do
                {
                    char choice;
                    count = 0;
                    cout << "What do you want to change?" << endl;
                    cout << "(N)Name." << endl;
                    cout << "(T)Type." << endl;
                    cout << "(B)Year of birth." << endl;
                    cout << "(M)Return to main menu." << endl;
                    cout << "Select a letter: ";
                    cin >> choice;

                    switch(choice)
                    {
                        case 'n':
                        case 'N':   updateCompName(id);
                                    break;
                        case 't':
                        case 'T':   updateCompType(id);
                                    break;
                        case 'b':
                        case 'B':   updateCompBYear(id);
                                    break;
                        case 'm':
                        case 'M':   return;
                                    break;
                        default:    count = -1;
                                    errorInput();
                                    updateCompMenu();
                                    break;
                    }
                 } while(count == -1);
            }
            else
            {
                cout << "No Computer has this id!" << endl;
                cin.clear();
                cin.ignore();
                updateSciMenu();
            }
       }
       else
       {
            errorInput();
            cin.clear();
            cin.ignore();
            updateCompMenu();
       }
}

void UI::updateCompName(const int id)
{
    string name;
    char ans;
    cout << "Please insert a new name: ";
    cin.ignore();
    getline(cin, name);
    Computer i1 = core.getData().getSingleComp(id);
    string oldname = i1.getName();
    cout << "Do you want to change Computer" << endl;
    cout << "From:" << endl;
    printComp(i1);
    core.updateCompName(name,id);
    cout << endl;
    cout << "To:" << endl;
    i1 = core.getData().getSingleComp(id);
    printComp(i1);
    cout << "Select letter(y/n): ";
    cin >> ans;
    while(cin.fail() || (ans!='y' && ans!='n'))
    {
        cin.clear();
        cin.ignore();
        cout << "Select letter(y/n): ";
        cin >> ans;
        if(cin.fail() || (ans!='y' && ans!='n'))
        {
            errorInput();
        }
    }
    if(ans == 'n')
    {
        core.updateCompName(oldname,id);
        cout << endl;
        cout << "No changes were made!" << endl;
    }
    else if(ans == 'y')
    {
        cout << endl;
         cout << "Update succecfull!" << endl;
    }
}

void UI::updateCompBYear(const int id)
{
    int year;
    char ans;
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Insert a new year of creation: ";
        cin >> year;
        if(cin.fail())
        {
            errorInput();
        }
    } while(cin.fail());

    Computer i1 = core.getData().getSingleComp(id);
    int old = i1.getYear();
    cout << "Do you want to change Computer" << endl;
    cout << "From:" << endl;
    printComp(i1);
    core.updateCompBYear(year,id);
    cout << endl;
    cout << "To:" << endl;
    i1 = core.getData().getSingleComp(id);
    printComp(i1);
    cout << "Select letter(y/n): ";
    cin >> ans;
    while(cin.fail() || (ans!='y' && ans!='n'))
    {
        cin.clear();
        cin.ignore();
        cout << "Select letter(y/n): ";
        cin >> ans;
        if(cin.fail() || (ans!='y' && ans!='n'))
        {
            errorInput();
        }
    }
    if(ans == 'n')
    {
        core.updateCompBYear(old,id);
        cout << endl;
        cout << "No changes were made!" << endl;
    }
    else if(ans == 'y')
    {
        cout << endl;
         cout << "Update succecfull!" << endl;
    }

}

void UI::updateCompType(const int id)
{
    string type;
    char ans;
    cout << "Please insert a new type: ";
    cin.ignore();
    getline(cin, type);
    Computer i1 = core.getData().getSingleComp(id);
    string oldtype = i1.getType();
    cout << "Do you want to change Computer" << endl;
    cout << "From:" << endl;
    printComp(i1);
    core.updateCompType(type,id);
    cout << endl;
    cout << "To:" << endl;
    i1 = core.getData().getSingleComp(id);
    printComp(i1);
    cout << "Select letter(y/n): ";
    cin >> ans;
    while(cin.fail() || (ans!='y' && ans!='n'))
    {
        cin.clear();
        cin.ignore();
        cout << "Select letter(y/n): ";
        cin >> ans;
        if(cin.fail() || (ans!='y' && ans!='n'))
        {
            errorInput();
        }
    }
    if(ans == 'n')
    {
        core.updateCompType(oldtype,id);
        cout << endl;
        cout << "No changes were made!" << endl;
    }
    else if(ans == 'y')
    {
        cout << endl;
         cout << "Update succecfull!" << endl;
    }
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
    bool found = false;
    int ansYear;
    cout << "Enter year of creation: ";
    cin >> ansYear;
    if(!cin.fail())
    {
        Machines result = core.searchComYear(found, ansYear);
        if(found)
        {
            entriesMatched();
            printComputers(result);
        }
        else if(!found)
        {
            cout << endl;
            noMatch();
            if(result.getSize() != 0)
            {
                cout << "However these computers were found within"
                        " a 10 year range of given year: " << endl;
                printComputers(result);
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
    result = core.searchComName(searchStr);
    if(result.getSize() != 0)
    {
        entriesMatched();
        printComputers(result);
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
    result = core.searchComType(searchStr);
    if(result.getSize() != 0)
    {
        entriesMatched();
        printComputers(result);
    }
    else
    {
        noMatch();
    }
}

void UI::searchSciName()
{
    People result;
    string searchStr;
    cin.ignore();
    cout << "Enter a name to search for: " ;
    getline(cin, searchStr);
    result = core.searchNam(searchStr);
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
    bool found = false;
    int ansYear;
    cout << "Enter a birth year: ";
    cin >> ansYear;
    if(!cin.fail())
    {
        People result = core.searchBir(found, ansYear);
        if(found)
        {
            entriesMatched();
            printList(result);
        }
        else if(!found)
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
    bool found = false;
    int ansYear;
    cout << "Enter a death year: ";
    cin >> ansYear;
    if(!cin.fail())
    {
        People result = core.searchDea(found, ansYear);
        if(found)
        {
            entriesMatched();
            printList(result);
        }
        else if(!found)
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

    do
    {
        cout << "Gender (m/f): ";
        cin >> gender;
        if(gender != 'f' && gender != 'm' && gender != 'F' && gender != 'M')
        {
            errorInput();
        }
    } while(gender != 'f' && gender != 'm' && gender != 'F' && gender != 'M');

    do
    {
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
    while((ans != 'y' &&ans != 'Y' && ans != 'n' && ans != 'N' ) || cin.fail())
    {
       if((ans != 'y' ||ans != 'Y' ||ans != 'n' || ans != 'N' ) || cin.fail())
       {
           errorInput();
           cin >> ans;
       }
    }

    if(ans == 'n' || ans == 'N')
    {
        do
        {
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
    else if(ans == 'y' || ans == 'Y')
    {
        death = 0;
    }
    Individual temp(surname, name, gender, birth, death);
    core.addIndividual(temp, notfound);
    if(notfound)
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
    while((ans != 'y' && ans != 'Y' && ans != 'n' && ans != 'N' ) || cin.fail())
    {
       if((ans != 'y' ||ans != 'Y' || ans != 'n' || ans != 'N' ) || cin.fail())
       {
           errorInput();
           cin >> ans;
       }
    }

    if(ans == 'y' || ans =='Y' )
    {
        cout << "Creation year: ";
        cin >> year;
    }
    else if(ans == 'n' || ans == 'N')
    {
        year = 0;
    }

    Computer temp(year, name, type);
    core.addComputer(temp, notfound);
    if(notfound)
    {
        cout << endl;
        cout << "This Computer is already in the database! " << endl;
    }
}

void UI::addConnection()
{
    int s, c;
    bool strue = false, ctrue = false;
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Please enter the id of the Scientist: ";
        cin >> s;
    } while(cin.fail());
   People p1 = core.getData().sortIndiAlphaFront();
   for(int i = 0; i < p1.getSize(); i++)
   {
       if(p1.getIndi(i).getId() == s)
       {
           strue = true;
       }
   }
   if(strue)
   {
       do
       {
           cin.clear();
           cin.ignore();
           cout << "Please enter the id of the Computer : ";
           cin >> c;
       } while(cin.fail());
       Machines c1 = core.getData().sortCompAlphaFront();
       for(int i = 0; i < c1.getSize(); i++)
       {
           if(c1.getComputer(i).getId() == c)
           {
               ctrue = true;
           }
       }
   }
   else
   {
       errorInput();
       addConnection();
   }

   if(strue && ctrue)
   {
       core.addConnection(s,c);
       Individual i = core.getData().getSingleIndi(s);
       Computer j = core.getData().getSingleComp(c);
       cout << "Linking successfull!" << endl;
       cout << "Scientist: " << i.getSurname() << " is now linked with computer: " << j.getName() << endl;
   }
   else
   {
       errorInput();
       addConnection();
   }
}

void UI::removeCom()
{
    int id;
    bool removed = false;
    cin.ignore();
    cout << endl;

    cout << "Type the id of the computer: ";
    cin >> id;

    core.removeComputer(id, removed);

    if(removed)
    {
        cout << "The computer has been removed." << endl;
    }
    else if(!removed)
    {
        cout << "The computer was not found in list and therefore not removed." << endl;
    }
}

void UI::removeSci()
{
    int id;
    bool removed = false;
    cin.ignore();
    cout << endl;
    cout << "Type the id of the individual: ";
    cin >> id;
    core.removeIndividual(id, removed);

    if(removed)
    {
        cout << "The individual has been removed." << endl;
    }
    else if(!removed)
    {
        cout << "The individual was not found in list and therefore not removed." << endl;
    }
}

void UI::removeConnection()
{
    int s,c;
    bool strue = false, ctrue = false;
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Please enter the id of the Scientist: ";
        cin >> s;
    } while(cin.fail());
   People p1 = core.getData().sortIndiAlphaFront();
   for(int i = 0; i < p1.getSize(); i++)
   {
       if(p1.getIndi(i).getId() == s)
       {
           strue = true;
       }
   }

   if(strue)
   {
       do
       {
           cin.clear();
           cin.ignore();
           cout << "Please enter the id of the computer : ";
           cin >> c;
       } while(cin.fail());

       Machines c1 = core.getData().sortCompAlphaFront();
       for(int i = 0; i < c1.getSize(); i++)
       {
           if(c1.getComputer(i).getId() == c)
           {
               ctrue = true;
               cout << "her";
           }
       }
   }

   else
   {
       errorInput();
       removeConnection();
   }

   if(strue && ctrue)
   {
       core.removeConnection(s,c);
       Individual i = core.getData().getSingleIndi(s);
       Computer j = core.getData().getSingleComp(c);
       cout << "Linking removed successfully!" << endl;
       cout << "Scientist: " << i.getSurname() << " is no longer linked with computer: " << j.getName() <<endl;
   }
}

void UI::printScientists(People& sci)
{
    cout << endl;
    cout << right << setw(3) << "Id" << "\t" << left << setw(30) << "Name" << setw(10) << "Gender" << "\tLife" << endl;
    for(int i = 0; i < 74; i++)
    {
        cout << "-";
    }

    cout << endl;
    for(int i = 0; i < sci.getSize(); i++)
    {
        Individual temp = sci.getIndi(i);
        printIndi(temp);
    }

    cout << endl;
}

void UI::printScientistsConnections(People& sci)
{
    cout << endl;
    cout << right << setw(3) << "Id" << "\t" << left << setw(30) << "Name" << setw(10) << "Gender" << "\tLife" << endl;

    for(int i = 0; i < 74; i++)
    {
        cout << "-";
    }
    cout << endl;

    for(int i = 0; i < sci.getSize(); i++)
    {
        Individual temp = sci.getIndi(i);
        printIndiAndConnect(temp);
    }

    cout << endl;
}

void UI::printComputers(Machines &comps)
{
    cout << endl;
    cout << right << setw(3) << "Id" << "\t" << left << setw(25) << "Name" << setw(15)
         << "Type" << "\tYear" << endl;
    for(int i = 0; i < 74; i++)
    {
        cout << "-";
    }

    cout << endl << endl;
    for(int i = 0; i < comps.getSize(); i++)
    {
        Computer temp = comps.getComputer(i);
        printComp(temp);
        cout << endl;
    }
}

void UI::printComputersConnection(Machines &comps)
{
    cout << endl;
    cout << right << setw(3) << "Id" << "\t" << left << setw(25) << "Name" << setw(15)
        << "Type" << "\tYear" << endl;

    for(int i = 0; i < 74; i++)
    {
        cout << "-";
    }
    cout << endl;

    for(int i = 0; i < comps.getSize(); i++)
    {
        Computer temp = comps.getComputer(i);
        printCompAndConnect(temp);
    }
}

void UI::printIndiIndent(Individual &id) const
{
    cout << "\t" << id.getId() << "\t" << id.getName() << " " << id.getSurname() << "\t";
    if(id.getGender() == 'f' || id.getGender() == 'F')
    {
        cout << "Female";
    }
    else
    {
        cout << "Male";
    }
    cout << "\t" << id.getBirth() << " - ";
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
    cout << "\t" << id.getId()<< "\t" << id.getName() << "\t" << id.getType() << "\t";
    if(id.getYear() == 0)
    {
        cout << "Not built";
    }
    else
    {
        cout << id.getYear();
    }
    cout << endl;
}

void UI::printConnectedComp(Machines& comps) const
{
    if(comps.getSize() > 0)
    {
        cout << "\t" << "Id" << "\t" << "Name" << endl;
        cout << "\t-----------------------" << endl;
        for(int i = 0; i < comps.getSize(); i++)
        {
            Computer temp = comps.getComputer(i);
            printCompIndent(temp);
        }
    }
}

void UI::printConnectedSci(People& sci) const
{
    if(sci.getSize() > 0)
    {
        cout << "\t" << "Id" << "\t" << "Name" << endl;
        cout << "\t-----------------------" << endl;

        for(int i = 0; i < sci.getSize(); i++)
        {
            Individual temp = sci.getIndi(i);
            printIndiIndent(temp);
        }
    }
    cout << endl;
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
    string name = temp.getSurname() + ", " + temp.getName();
    cout << endl;
    cout << right << setw(3) << temp.getId() << "\t" << left << setw(30) << name << setw(10);// << "\t";
    if(temp.getGender() == 'f' || temp.getGender() == 'F')
    {
        cout << "Female";
    }
    else
    {
        cout << "Male";
    }

    cout << "\t";
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

void UI::printIndiAndConnect(Individual& sci)
{
    printIndi(sci);
    int id = sci.getId();
    Machines temp = core.getConnectedComp(id);
    printConnectedComp(temp);
}

void UI::printCompAndConnect(Computer& comp)
{
    printComp(comp);
    int id = comp.getId();
    People temp = core.getConnectedSci(id);
    printConnectedSci(temp);
}
/*
void UI::printComplist(Machines& complist) const
{
    for (int i = 0; i < complist.getSize(); i++)
    {
        Computer com = complist.getComputer(i);
        printComp(com);
    }
}*/

void UI::printComp(Computer& temp) const
{
    cout << right << setw(3) << temp.getId() << "\t" << left << setw(25) << temp.getName() << setw(15)
         << temp.getType() << "\t";

    if(temp.getYear() != 0)
    {
        cout << temp.getYear() << endl;
    }
    else
    {
        cout << "Not built." << endl;
    }
}

void UI::searchSciLink()
{
    cout << endl;
    bool found = false;
    int id;
    cout << "Enter scientist ID: " ;
    cin >> id;
    if(!cin.fail())
    {
         People p = core.getData().sortIndiAlphaFront();
         for(int i = 0; i < p.getSize(); i++)
         {
             if(id == p.getIndi(i).getId())
             {
                 found = true;
             }
         }
         if(found == true)

         {
             Machines mac = core.getConnectedComp(id);
             Individual i1 = core.getData().getSingleIndi(id);
             string s = i1.getName() + " " + i1.getSurname();
             cout << "You picked the scientist " << s << " is that correct(y/n)? ";
             char input;
             cin >> input;
             while((input != 'y' && input != 'Y' && input != 'n'&& input != 'N') || cin.fail())
             {
                if((input != 'y' || input != 'Y' || input != 'n' || input != 'N') || cin.fail())
                {
                    errorInput();
                    cin >> input;
                }
             }
             if(input == 'n' || input == 'N')
             {
             searchSciLink();
             }
             else if(input == 'y' || input == 'Y' )
             {
                 if(mac.getSize() == 0)
                 {
                     cout << "No computers connected to this scientist" << endl;
                 }

                 else
                {
                     cout << endl;
                     cout << "The following computers are connected to the scientist " << s << ": " << endl;
                     printComputers(mac);
                }
             }
         }
         else
         {
             cout << "No scientist has this id!" << endl;
             cin.clear();
             cin.ignore();
             searchSciLink();
         }
    }
    else
    {
        errorInput();
        cin.clear();
        cin.ignore();
        searchSciLink();
    }
}

void UI::searchComLink()
{
    cout << endl;
    bool found = false;
    int id;
    cout << "Enter computer ID: ";

    cin >> id;
    if(!cin.fail())
    {
        Machines mac = core.getData().sortCompAlphaFront();
        for(int i = 0; i < mac.getSize(); i++)
        {
            if(id == mac.getComputer(i).getId())
            {
               found = true;

            }
        }
         if(found == true)
         {   People p = core.getConnectedSci(id);
             Computer c1 = core.getData().getSingleComp(id);
             string s = c1.getName();
             cout << "You picked the computer "<< s <<" is that correct(y/n)? ";
             char input;
             cin >> input;
             while((input != 'y' && input != 'Y' && input != 'n' && input != 'N' ) || cin.fail())
             {
                if((input != 'y' || input != 'Y' || input != 'n' || input != 'N' ) || cin.fail())
                {
                    errorInput();
                    cin >> input;
                }
             }
             if(input == 'n' || input == 'N')
             {
                 searchComLink();
             }
             else if(input == 'y' || input == 'Y')
             {
                  if(p.getSize() == 0)
                  {
                      cout << "No scientists connected to this computer" << endl;
                  }
                  else
                  {
                      cout << endl;
                      cout << "The following scientists are connected to computer " << s << ": " << endl;
                      printList(p);
                  }
              }                 
         }
         else
         {
             cout << "No computer has this id!" << endl;
             cin.clear();
             cin.ignore();
             searchComLink();
         }
    }
    else
    {
         errorInput();
         cin.clear();
         cin.ignore();
         searchComLink();
    }
}

void UI::sortSciLink()
{
    People temp = core.sortSciAlpabetFront();
    printScientistsConnections(temp);
}

void UI::sortComLink()
{
    Machines temp = core.sortCompAlpabetBack();
    printComputersConnection(temp);
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

void UI::clearScreen()
{
    system("cls||clear");
}

