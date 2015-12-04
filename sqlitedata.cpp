#include "sqlitedata.h"

SQLiteData::SQLiteData()
{

}
People SQLiteData::getIndiFromBase()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "ScientistsComputers.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    QSqlQuery queryname(db);
    queryname.exec("SELECT * FROM Scientist as s WHERE s.deleted =0 " );
    People p1;
    while(queryname.next())
    {
        int id  = queryname.value("id").toUInt();
        string surname = queryname.value("surname").toString().toStdString();
        string name = queryname.value("name").toString().toStdString();
        char gender = queryname.value("gender").toChar().toLatin1();
        int byear  = queryname.value("byear").toUInt();
        int dyear  = queryname.value("dyear").toUInt();
        Individual i1(surname,name,gender,byear,dyear);
        p1.addIndi(i1);
    }
    db.close();
    return p1;

}

Machines SQLiteData::getCompFromBase()
{

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "ScientistsComputers.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    QSqlQuery queryname(db);
    queryname.exec("SELECT * FROM Computer as s WHERE s.deleted =0 " );
    Machines p1;
    while(queryname.next())
    {
        int id  = queryname.value("id").toUInt();
        string name = queryname.value("name").toString().toStdString();
        string type = queryname.value("type").toString().toStdString();
        int byear  = queryname.value("byear").toUInt();
        Computer c1(id,byear,name,type);
        p1.addMach(c1);
    }
    db.close();
    return p1;

}
