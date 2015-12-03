#include <QCoreApplication>
#include <iostream>

#include "ui.h"

using namespace std;

int main()
{
    UI ui("People.txt");
    ui.run();


/*    People list(FILENAME);
    welcomeMessage(list);

    char choice;
    do {
        ask();
        cin >> choice;
        menu(choice, list);
    } while (true);*/
}
