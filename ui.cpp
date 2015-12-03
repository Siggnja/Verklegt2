#include "ui.h"

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
        ask();
        cin >> choice;
        menu(choice);
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
    cout << "--- The following people match your search ---" << endl;
}

void UI::noMatch()
{
    cout << "No one matched your search." << endl;
}

void UI::inDatabase()
{
    cout << "This individual is already in the database " << endl;
}

void UI::readingString(string gender)
{
    cout << "--- Reading " << gender << " ---" << endl;
}

void UI::ask() {
    cout << endl;
    cout << "Do you want to: " << endl;
    cout << "(A) Add to list? " << endl;
    cout << "(S) Search list? " << endl;
    cout << "(P) Print list? " << endl;
    cout << "(L) Print list size?" << endl;
    cout << "(R) Remove from list? " << endl;
    cout << "(Q) Quit program. " << endl;
    cout << "Select a letter: ";
}

void UI::menu(char ans)
{
    switch(ans) {
        case 'a':
        case 'A':   addIndividual();
                    break;
        case 's':
        case 'S':
                    searchMenu();
                    break;
        case 'p':
        case 'P':   sortMenu();
                    break;
        case 'r':
        case 'R':   remove();
                    break;
        case 'l':
        case 'L':   cout << "The current size of this list is: " << core.getSizeOfList() << endl;
                    break;
        case 'q':
        case 'Q':   cout << endl;
                    exit(1);
                    break;
        default:    cout << "Incorrect input, please try again!" << endl;
                    break;
    }
}

void UI::searchMenu()
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
        case 'N':   searchName(); //<- breyta í core.searchName þegar core hefur það fall
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
                    searchMenu();
    }
}

void UI::sortMenu()
{
    char choice;
    cout << endl;
    cout << "Print/Sort by: " << endl;
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
        case 'U':   this->print();
                    break;

        case 'a':
        case 'A':   cout << endl << "--- Printing by alphabetical order --- " << endl;
                    core.sortAlpabetFront();
                    this->print();
                    break;
        case 'r':
        case 'R':   cout << endl << "--- Printing by reverse alphabetical order --- " << endl;
                    core.sortAlpabetBack();
                    this->print();
                    break;
        case 'b':
        case 'B':   cout << endl << "--- Printing by year of Birth --- " << endl;
                    core.sortByBirthYear();
                    this->print();
                    break;
        case 'd':
        case 'D':
                    cout << endl << "--- Printing by year of Death --- " << endl;
                    core.sortByDeathYear();
                     this->print();
                    break;
        case 'M':
        case 'm':   this->searchMenu();
                    break;

        case 'q':
        case 'Q':   exit(1);
                    break;
        default:    errorInput();
                    sortMenu();
    }
}

void UI::welcomeMessage()
{
    cout << "------------Welcome to the database of famous computer scientists-------------" << endl;
    cout << "\t" << "    In this database you can add, remove, sort and search" << endl;
    cout << "\t \t" <<" At this moment we have "<< core.getList().getSize() << " computer scientists!" << endl;
    cout << "------------------------------------Enjoy!------------------------------------" << endl;
}

void UI::addIndividual()
{
    string surname, name;
    int birth, death;
    char gender;
    //bool found = false;

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
            cout << "Invalid input, please try again!" << endl << endl;
    } while(gender != 'f' && gender != 'm' && gender != 'F' && gender != 'M');

    do {
        cin.clear();
        cin.ignore();
        cout << "Year of birth: ";
        cin >> birth;
        if(cin.fail())
        {
            cout << endl << "Invalid input, please try again!" << endl << endl;
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
                cout << endl << "Invalid input, please try again!" << endl << endl;
            }
            if(birth>death)
            {
                cout<<"Illegal deathyear! Input again: "<<endl<<endl;
            }
        } while(cin.fail()||birth>death);
    }
    else {
        death = 0;
    }

    Individual temp(surname, name, gender, birth, death); //fer inn i add
    core.addIndividual(temp);
}
// a eftir ad klara


void UI::printIndi(int i) const
{
    Individual temp = core.getList().getIndi(i);
    cout << endl;
    cout << "Name: " << temp.getName() << " " << temp.getSurname() << endl;

    if(temp.getGender() == 'f' || temp.getGender() == 'F')
    {
        cout << "female" << endl;
    }
    else
    {
        cout << "male" << endl;
    }
    //cout << temp.getGender() << endl;
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

    if(temp.getGender() == 'f' || temp.getGender() == 'F')
    {
        cout << "female" << endl;
    }
    else
    {
        cout << "male" << endl;
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

void UI::remove()
{
    string str;
    cin.ignore();
    cout << endl;
    cout << "Type exactly the name of the individual:" << endl;
    getline(cin, str);
    core.removeIndividual(str);

}



void UI::searchName()
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

void UI::searchGender()
{
    People result;
    char ansGender;
    cout << endl;
    cout << "Enter which gender you want to search for (m/f): ";
    cin >> ansGender;
    cout << endl;
    if(ansGender == 'm' || ansGender == 'M' || ansGender=='f' || ansGender=='F')
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
        this->searchGender();
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
        this->searchBirth();
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
        this->searchDeath();
    }
}
void UI::print()
{
    cout << endl;
    for(int i = 0 ; i < core.getList().getSize() ; i++)
    {

        cout << "Name: " << core.getList().getIndi(i).getSurname() + ", " + core.getList().getIndi(i).getName()<<endl;
        cout << "Gender: ";
        if(core.getList().getIndi(i).getGender() == 'm' || core.getList().getIndi(i).getGender() == 'M')
        {
            cout << "Male" << endl;
        }
        else
        {
            cout << "Female" << endl;
        }


        cout << core.getList().getIndi(i).getBirth() << " - ";
        if(core.getList().getIndi(i).getDeath() == 0)
        {
            cout << "Today" << endl;
        }
        else
        {
            cout << core.getList().getIndi(i).getDeath()<<endl;
        }
        cout << endl;
    }
}
