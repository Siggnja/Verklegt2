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
        case 'A':
                    break;
        case 's':
        case 'S':
                    searchMenu();
                    break;
        case 'p':
        case 'P':   sortMenu();
                    break;
        case 'r':
        case 'R':
                    break;
        case 'l':
        case 'L':   cout << "The size of this list is: " << core.getSizeOfList() << endl;
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
        case 'N':   //p.searchName();
                    break;
        case 'g':
        case 'G':   //p.searchGender();
                    break;
        case 'b':
        case 'B':   //p.searchBirth();
                    break;
        case 'd':
        case 'D':   //p.searchDeath();
                    break;
        case 'M':
        case 'm':
                    break;
        case 'q':
        case 'Q':   exit(1);
                    break;
        default:    //errorInput();
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
         << "(G) Gender" << endl
         << "(M) Return to Menu" << endl
         << "(Q) Quit program " << endl;
    cout << "Select a letter: ";
    cin >> choice;

    switch(choice) {
        case 'u':
        case 'U':
                    break;

        case 'a':
        case 'A':   cout << endl << "--- Printing by alphabetical order --- " << endl;
                    break;
        case 'r':
        case 'R':   cout << endl << "--- Printing by reverse alphabetical order --- " << endl;
                    break;
        case 'b':
        case 'B':   cout << endl << "--- Printing by year of Birth --- " << endl;
                    break;
        case 'd':
        case 'D':

                    break;
        case 'g':
        case 'G':
                    break;
        case 'M':
        case 'm':   break;

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
    cout << "\t \t" <<" At this moment we have "<< core.getSizeOfList() << " computer scientists!" << endl;
    cout << "------------------------------------Enjoy!------------------------------------" << endl;
}

void UI::searchName()
{
    People result;
    bool found = false;
    string tempStr, searchStr = "";
    cin.ignore();   //annars virkar getline ekki
    cout << "Enter a name to search for: " ;
    getline(cin, searchStr);

    individualsMatched();
    core.searchNam(found, searchStr, result);

    //core.sortAlpabetFront();
    if (found == false)
    {
        noMatch();
    }
}
