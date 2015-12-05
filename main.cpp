#include <QCoreApplication>
#include <iostream>
#include "people.h"
#include "ui.h"
#include "dataread.h"
#include "individual.h"
#include "core.h"
#include "sqlitedata.h"
#include <QtSql>
//#include <string>

using namespace std;


int main()
{
    SQLiteData s;

    int i = 1990;
    char g = 'm';
    People p1 = s.searchByGender(g);
    for(int i = 0; i < p1.getSize(); i++)
    {
       cout << p1.getIndi(i).getSurname() << " ";
       cout << p1.getIndi(i).getGender() << endl;
    }

/*
    Machines p1 = s.sortCompByType();
    //cout << p1.getSize();
    for(int i = 0; i < p1.getSize(); i++)
    {
       cout << p1.getComputer(i).getName() << " ";
       cout << p1.getComputer(i).getYear() << " ";
       cout << p1.getComputer(i).getType() << endl;
    }
 */
   // UI ui("people.txt");
  //  ui.run();

}
void test()
 {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Vika2";
    db.setDatabaseName(dbName);
    db.open();
}

