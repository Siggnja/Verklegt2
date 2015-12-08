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
    cout << "(C) Change information?"<<endl;
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
    cout<<endl;
    cout << "Do you want to: " << endl;
    cout << "(S) Search for a scientist and return computers he is connected to?" << endl;
    cout << "(C) Search for a computer and return scientists he is connected to? " << endl;
    cout << "(M) Return to menu? " << endl;
    cout << "(Q) Quit program. " << endl;
    cout << "Select a letter: ";
    char ans;
    cin >>ans;
    switch(ans)
    {
          case 's':
          case 'S':
                    searchSciLink();
                    break;
          case 'c':
          case 'C':
                    searchComLink();
                    break;
          case 'm':
          case 'M':
                    return;
                    break;
          case 'q':
          case 'Q':
                    cout << endl;
                    exit(1);
                    break;
          default:
                    errorInput();
                    break;

    }
}

void UI::printLinkMenu()
{
    cout<<endl;
    cout << "Do you want to: " << endl;
    cout << "(S) Print scientists and computers connected to them?" << endl;
    cout << "(C) Print computers and scientists connected to them? " << endl;
    cout << "(M) Return to menu? " << endl;
    cout << "(Q) Quit program. " << endl;
    cout << "Select a letter: ";
    char ans;
    cin >>ans;
    switch(ans)
    {
          case 's':
          case 'S':
                    sortSciLink();
                    break;
          case 'c':
          case 'C':
                    sortComLink();
                    break;
          case 'm':
          case 'M':
                    return;
                    break;
          case 'q':
          case 'Q':
                    cout << endl;
                    exit(1);
                    break;
          default:
                    errorInput();
                    break;
    }

}


void UI::linkMenu()
{   cout<<endl;
    cout << "Do you want to: " << endl;
    cout << "(S) Search connections?"<<endl;
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

void UI::updateSciMenu()
{
    int id,count;
    bool found=false;
    cout << "Please enter the id of the Scientist you want to change: ";
    cin >> id;
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
                cout << "(N)Name" << endl;
                cout << "(S)Surname" << endl;
                cout << "(B)Year of birth" << endl;
                cout << "(D)Year of death" << endl;
                cout << "(G)Gender" << endl;
                cout << "(M)Return to main menu" << endl;
                cout << "Select a letter: ";
                cin >> choice;
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
                    case 'M':
                                return;
                                break;


                    default:    count = -1;
                                errorInput();
                                updateSciMenu();
                                break;

                }
             }while(count==-1);
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
    cout << "Please insert a new name: ";
    cin.ignore();
    getline(cin, name);
    core.updateIndiName(name,id);
    cout << "The scientist is now registered as:" << endl;
    Individual i1 = core.getData().getSingleIndi(id);
    printIndi(i1);
}

void UI::updateIndiSurname(const int id)
{
    string surname;
    cout << "Please insert a new surname: ";
    cin.ignore();
    getline(cin, surname);
    core.updateIndiSurname(surname,id);
    cout << "The scientist is now registered as:" << endl;
    Individual i1 = core.getData().getSingleIndi(id);
    printIndi(i1);
}
void UI::updateIndiGender(const int id)
{
    Individual i1 =core.getData().getSingleIndi(id);
    if(i1.getGender()=='m')
    {
        core.updateIndiGender('f',id);
        cout << "--- Changing the scientist from male to female ---" << endl;
    }
    else
    {
        core.updateIndiGender('m',id);
        cout << "--- Changing the scientist from female to male ---" << endl;
    }
    i1=core.getData().getSingleIndi(id);
    cout << "The scientist is now registered as:" << endl;
    printIndi(i1);
}

void UI::updateIndiBYear(const int id)
{
    int year;
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
    }while(cin.fail());
    Individual i1 = core.getData().getSingleIndi(id);
    if(i1.getDeath()>year)
    {
        core.updateIndiBYear(year,id);
    }
    else
    {
        errorInput();
        updateIndiBYear(id);
    }
    i1 = core.getData().getSingleIndi(id);
    cout << "The scientist is now registered as:" << endl;
    printIndi(i1);
}

void UI::updateIndiDYear(const int id)
{
    int year;
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Insert a new daeth year: ";
        cin >> year;
        if(cin.fail())
        {
            errorInput();
        }
    }while(cin.fail());
    Individual i1 = core.getData().getSingleIndi(id);
    if(i1.getBirth()>year)
    {
        core.updateIndiBYear(year,id);
    }
    else
    {
        errorInput();
        updateIndiBYear(id);
    }
    i1 = core.getData().getSingleIndi(id);
    cout << "The scientist is now registered as:" << endl;
    printIndi(i1);
}

void UI::updateCompMenu()
{
        int id,count;
        bool found=false;
        cout << "Please enter the id of the Computer you want to change: ";
        cin >> id;
        if(!cin.fail())
        {
            Machines c1 = core.getData().sortCompAlphaFront();
            for(int i = 0 ; i <c1.getSize(); i++)
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
                    cout << "(N)Name" << endl;
                    cout << "(T)Type" << endl;
                    cout << "(B)Year of birth" << endl;
                    cout << "(M)Return to main menu" << endl;
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
                        case 'M':
                                    return;
                                    break;
                        default:    count = -1;
                                    errorInput();
                                    updateCompMenu();
                                    break;

                    }
                 }while(count==-1);
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
    cout << "Please insert a new name: ";
    cin.ignore();
    getline(cin, name);
    core.updateCompName(name,id);
    cout << "The Computer is now registered as:" << endl;
    Computer i1 = core.getData().getSingleComp(id);
    printComp(i1);
}

void UI::updateCompBYear(const int id)
{
    int year;
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
    }while(cin.fail());
    core.updateIndiBYear(year,id);
    Computer i1 = core.getData().getSingleComp(id);
    cout << "The Computer is now registered as:" << endl;
    printComp(i1);
}

void UI::updateCompType(const int id)
{
    string type;
    cout << "Please insert a new type: ";
    cin.ignore();
    getline(cin, type);
    core.updateCompName(type,id);
    cout << "The Computer is now registered as:" << endl;
    Computer i1 = core.getData().getSingleComp(id);
    printComp(i1);
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

    result = core.searchComName(searchStr);

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

    result = core.searchComType(searchStr);

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
    string searchStr;
    cin.ignore();
    cout << "Enter a name to search for: " ;
    getline(cin, searchStr);

    result = core.searchNam(searchStr);

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
    while((ans !='y'&&ans !='Y'&&ans !='n'&& ans !='N')||cin.fail())
    {
       if((ans !='y'||ans !='Y'||ans !='n'|| ans !='N')||cin.fail())
       {
           errorInput();
           cin>>ans;
       }
    }
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
    else if(ans =='y'||ans =='Y')
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
    while((ans !='y'&&ans !='Y'&&ans !='n'&& ans !='N')||cin.fail())
    {
       if((ans !='y'||ans !='Y'||ans !='n'|| ans !='N')||cin.fail())
       {
           errorInput();
           cin>>ans;
       }
    }

    if(ans == 'y'|| ans =='Y')
    {
        cout << "Creation year: ";
        cin >> year;
    }
    else if(ans =='n'|| ans =='N')
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
    int s,c;
    bool strue=false,ctrue=false;
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Please enter the id of the Scientist: ";
        cin >> s;
    }while(cin.fail());
   People p1 = core.getData().sortIndiAlphaFront();
   for(int i = 0; i<p1.getSize();i++)
   {
       if(p1.getIndi(i).getId()==s)
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
       }while(cin.fail());
       Machines c1 = core.getData().sortCompAlphaFront();
       for(int i = 0; i<c1.getSize();i++)
       {
           if(c1.getComputer(i).getId()==c)
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
       cout << "Linking succecfull!" << endl;
       cout << "Scientist: " << i.getSurname() << " is now linked with computer: " << j.getName() <<endl;
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

    if (removed)
    {
        cout << "The computer has been removed." << endl;

    }
    else if (!removed)
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

    if (removed)
    {
        core.removeIndividual(id, removed); //
        cout << "The individual has been removed." << endl;
    }
    else if (!removed)
    {
        cout << "The individual was not found in list and therefore not removed." << endl;
    }
}

void UI::removeConnection()
{
    int s,c;
    bool strue=false,ctrue=false;
    do
    {
        cin.clear();
        cin.ignore();
        cout << "Please enter the id of the Scientist: ";
        cin >> s;
    }while(cin.fail());
   People p1 = core.getData().sortIndiAlphaFront();
   for(int i = 0; i<p1.getSize();i++)
   {
       if(p1.getIndi(i).getId()==s)
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
       }while(cin.fail());
       Machines c1 = core.getData().sortCompAlphaFront();
       for(int i = 0; i<c1.getSize();i++)
       {
           if(c1.getComputer(i).getId()==s)
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
       core.removeConnection(s,c);
       Individual i = core.getData().getSingleIndi(s);
       Computer j = core.getData().getSingleComp(c);
       cout << "Linking removed succecfully!" << endl;
       cout << "Scientist: " << i.getSurname() << " is no longer linked with computer: " << j.getName() <<endl;
   }

}

void UI::printScientists(People& sci)
{
    cout << endl;
    cout << "Id\t" << "Name\t\t" << "Gender \t" << "Life" << endl;

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
    for(int i = 0; i < comps.getSize(); i++)
    {
        Computer temp = comps.getComputer(i);
        printComp(temp);
    }
}

void UI::printComputersConnection(Machines &comps)
{
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
        cout<<"Connection "<<(i+1)<<": ";
        Computer temp = comps.getComputer(i);
        printCompIndent(temp);
    }
}

void UI::printConnectedSci(People& sci) const
{

    for(int i = 0; i < sci.getSize(); i++)
    {
        cout<<"Connection "<<(i+1)<<": ";
        Individual temp = sci.getIndi(i);
        printIndiIndent(temp);
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
    /*cout << "Id: " << temp.getId() << endl;
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
    }*/

    cout << temp.getId() << "\t" << temp.getSurname() << ", " << temp.getName() << "\t";

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

void UI::printIndiAndConnect(Individual & sci)
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
    cout << "Id: " << temp.getId() << endl;
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
void UI::searchSciLink()

{   cout<<endl;
    bool found = false;
    int id;
    cout << "Enter scientist ID: " ;
    cin >>id;
    if(!cin.fail())
    {
         People p = core.getData().sortIndiAlphaFront();
         for(int i = 0 ; i <p.getSize(); i++)
         {
             if(id == p.getIndi(i).getId())
             {
                 found=true;
             }
         }
         if(found==true)

         {
             Machines mac=core.getConnectedComp(id);
             Individual i1 = core.getData().getSingleIndi(id);
             string s = i1.getName()+" "+i1.getSurname();
             cout<<"You picked the scientist "<<s<<" is that correct(y/n)?";
             char input;
             cin>>input;
             while((input !='y'&&input !='Y'&&input !='n'&& input !='N')||cin.fail())
             {
                if((input !='y'||input !='Y'||input !='n'|| input !='N')||cin.fail())
                {
                    errorInput();
                    cin>>input;
                }
             }
             if(input=='n'||input =='N')
             {
             searchSciLink();
             }
             else if(input =='y'||input =='Y')
             {
                 if(mac.getSize()==0)
                 {
                     cout<<"No computers connected to this scientist"<<endl;
                 }

                 else
                {
                     cout<<endl;
                     cout<<"The following computers are connected to the scientist "<<s<<":"<<endl;
                     printComplist(mac);
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
{   cout<<endl;
    bool found = false;
    int id;
    cout << "Enter computer ID: ";

    cin >>id;
    if(!cin.fail())
    {
        Machines mac = core.getData().sortCompAlphaFront();
        for(int i = 0 ; i <mac.getSize(); i++)
        {
            if(id == mac.getComputer(i).getId())
            {
               found=true;

            }
        }
         if(found==true)
         {   People p=core.getConnectedSci(id);
             Computer c1 = core.getData().getSingleComp(id);
             string s = c1.getName();
             cout<<"You picked the computer "<<s<<" is that correct(y/n)?";
             char input;
             cin>>input;
             while((input !='y'&&input !='Y'&&input !='n'&& input !='N')||cin.fail())
             {
                if((input !='y'||input !='Y'||input !='n'|| input !='N')||cin.fail())
                {
                    errorInput();
                    cin>>input;
                }
             }
             if(input=='n'||input =='N')
             {
                 searchComLink();
             }
             else if(input =='y'||input =='Y')
             {
                  if(p.getSize() == 0)
                  {
                      cout << "No scientists connected to this computer" << endl;
                  }
                  else
                  {
                      cout<<endl;
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
