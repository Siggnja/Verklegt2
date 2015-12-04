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
    Machines p1 = s.sortCompAlphaFront();
    for(int i = 0; i < p1.getSize(); i++)
    {
       cout << p1.getComputer(i).getName() << endl;
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

