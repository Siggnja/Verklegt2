#include <QCoreApplication>
#include <iostream>
#include "people.h"
using namespace std;

void ask();
//asks what should be done with the list
void menu(char ans, People& list);
//call for changes to the list
void searchMenu(People& p);
//choose what shall be searched for
void sortMenu(People& p);
//choose in what order the list shall be printed
void welcomeMessage(People& p);

int main()
{
    People list(FILENAME);
    welcomeMessage(list);

    char choice;
    do {
        ask();
        cin >> choice;
        menu(choice, list);
    } while (true);
}

void ask() {
    cout << endl;
    cout << "Do you want to: " << endl;
    cout << "(A) Add to list? " << endl;
    cout << "(S) Search list? " << endl;
    cout << "(P) Print list? " << endl;
    cout << "(R) Remove from list? " << endl;
    cout << "(Q) Quit program. " << endl;
    cout << "Select a letter: ";
}

void menu(char ans, People& list)
{
    switch(ans) {
        case 'a':
        case 'A':   {
                        cin.ignore();
                        Individual id;
                        cin >> id;
                        list.addIndi(id);
                    }
                    break;
        case 's':
        case 'S':   searchMenu(list);
                    break;
        case 'p':
        case 'P':   sortMenu(list);
                    break;
        case 'r':
        case 'R':   list = list.removeIndi();
                    break;
        case 'q':
        case 'Q':   exit(1);
                    break;
        default:    cout << "Incorrect input, please try again!" << endl;
                    break;
    }
}


void searchMenu(People& p)
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
        case 'N':   p.searchName();
                    break;
        case 'g':
        case 'G':   p.searchGender();
                    break;
        case 'b':
        case 'B':   p.searchBirth();
                    break;
        case 'd':
        case 'D':   p.searchDeath();
                    break;
        case 'M':
        case 'm':
                    break;
        case 'q':
        case 'Q':   exit(1);
                    break;
        default:    cout << "Incorrect input, please try again!" << endl;
                    searchMenu(p);
    }
}

void sortMenu(People& p)
{
    char choice;
    cout << endl;
    cout << "Print/Sort by: " << endl;
    cout << "(A) Alphabetic order" << endl
         << "(R) Reverse alphabetic order" << endl
         << "(B) Year of Birth" << endl
         << "(D) Year of Death" << endl
         << "(G) Gender" << endl
         << "(M) Return to Menu" << endl
         << "(Q) Quit program " << endl;
    cout << "Select a letter: ";
    cin >> choice;

    switch(choice) {
        case 'a':
        case 'A':   cout << endl << "--- Printing by alphabetical order --- " << endl;
                    p.sortAlpabetFront();
                    break;
        case 'r':
        case 'R':   cout << endl << "--- Printing by reverse alphabetical order --- " << endl;
                    p.sortAlpabetBack();
                    break;
        case 'b':
        case 'B':   cout << endl << "--- Printing by year of Birth --- " << endl;
                    p.sortByBirthYear();
                    break;
        case 'd':
        case 'D':   cout << endl << "--- Printing by year of Death --- " << endl;
                    p.sortByDeathYear();
                    break;
        case 'g':
        case 'G':   p.sortByGender();
                    break;
        case 'M':
        case 'm':   break;

        case 'q':
        case 'Q':   exit(1);
                    break;
        default:    cout << "Incorrect input, please try again!" << endl;
                    sortMenu(p);
    }
}

void welcomeMessage(People& p)
{
    cout << "------------Welcome to the database of famous computer scientists-------------" << endl;
    cout << "\t" << "    In this database you can add, remove, sort and search" << endl;
    cout << "\t \t" <<" At this moment we have "<< p.getSize() << " computer scientists!" << endl;
    cout << "------------------------------------Enjoy!------------------------------------" << endl;
}
