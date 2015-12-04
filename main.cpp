#include <QCoreApplication>
#include <iostream>
#include "people.h"
#include "ui.h"
#include "dataread.h"
#include "individual.h"
#include "core.h"
#include "sqlitedata.h"
#include<QtSql>
using namespace std;


int main()
{
    SQLiteData s;
    People p1 = s.sortIndiAlphaFront();
    for(int i = 0; i < p1.getSize(); i++)
    {
       cout << p1.getIndi(i).getSurname() << endl;
    }

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

