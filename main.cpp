#include <QCoreApplication>
#include <iostream>
#include "people.h"
#include "ui.h"
#include "dataread.h"
#include "individual.h"
#include "core.h"
#include<QtSql>
using namespace std;



int main()
{
    UI ui("people.txt");
    ui.run();

}
/*void test()
 {
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Vika2";
    db.setDatabaseName(dbName);
    db.open();
}
*/
