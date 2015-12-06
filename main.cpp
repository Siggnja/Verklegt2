#include <QCoreApplication>
#include <iostream>
//#include "people.h"
#include "ui.h"
//#include "dataread.h"
//#include "individual.h"
//#include "core.h"
//#include "sqlitedata.h"
#include <QtSql>
//#include <string>

using namespace std;


int main()
{
    SQLiteData s;
    ///*
    int i = 1905;
    char g = 'm';
    string name = "a";
    Individual i1("Siggi", "Njalli",'m',1994,0);
    s.addNewIndi(i1);
    /*
    People p1 = s.searchIndiBySurname("");
    for(int i = 0; i < p1.getSize(); i++)
    {
       cout << p1.getIndi(i).getSurname() << " ";
       cout << p1.getIndi(i).getName() << " ";
       cout << p1.getIndi(i).getBirth() << endl;
    }
    */
    //string name = "engine";
    //cout << p1.getSize();
    /*
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

