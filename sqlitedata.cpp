#include "sqlitedata.h"

SQLiteData::SQLiteData()
{

}
People SQLiteData::getIndiFromBase()
{
    QSqlDatabase db;
    QSqlDatabase::addDatabase("QSQLITE");
    QString dbName =  "ScientistsComputers.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    QSqlQuery queryname(db);
    queryname.exec("SELECT * FROM Scientist as s WHERE s.deleted =0 " );
    People p1;
    while(queryname.next())
    {
        string surname = queryname.value("surname").toString().toStdString();
        string name = queryname.value("name").toString().toStdString();
        char gender = queryname.value("gender").toChar().toLatin1();
        int byear  = queryname.value("byear").toUInt();
        int dyear  = queryname.value("dyear").toUInt();
        Individual i1(surname,name,gender,byear,dyear);
        p1.addIndi(i1);
    }
    return p1;
}
