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

   // SQLiteData s;
   // Individual c1 = s.getSingleIndi(3);
   // cout << c1.getName();
    //Computer i1(1994,"Siggi","monsi");
   // s.addNewComp(i1);
    //SQLiteData s;
    //cout << s.getSingleComp(1).getName() << "<<<-----" << endl;
    //SQLiteData s;
    //Computer i1(1994,"Siggi","monsi");
    // s.addNewComp(i1);
    //SQLiteData s;
    //Core c1;
    /*

    int i = 1905;
    char g;
    string name = "a";
    //SQLiteData s;
    //
    //int i = 1905;
    //char g = 'm';
    //string name = "a";
    */
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
    // s.updateCompType("Electronic",2);
    //cout << p1.getSize();
    /*
    for(int i = 0; i < p1.getSize(); i++)
    {
       cout << p1.getComputer(i).getName() << " ";
       cout << p1.getComputer(i).getYear() << " ";
       cout << p1.getComputer(i).getType() << endl;
    }
    */
    UI ui;
    ui.run();

}
void test()
 {
    //QSqlDatabase db;
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbName = "Vika2";
    //db.setDatabaseName(dbName);
    //db.open();
}

