#include <QCoreApplication>
#include <iostream>
#include "people.h"
using namespace std;



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
