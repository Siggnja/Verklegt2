#include "sqlitedata.h"


SQLiteData::SQLiteData()
{

}
People SQLiteData::sortIndiAlphaFront()
{
    string Query = selectAllSci + " " + orderBySurname;
    People p1 = doQuerySci(Query);
    return p1;
}
Machines SQLiteData::sortCompAlphaFront()
{
    string Query = selectAllComp + " " + orderByName;
    Machines p1 = doQueryComp(Query);
    return p1;


}
People SQLiteData::sortIndiAlphaBack()
{
    string Query = selectAllSci + " " + orderBySurnameDe;
    People p1 = doQuerySci(Query);
    return p1;
}
People SQLiteData::sortIndiBYear()
{
    string Query = selectAllSci + " " + orderByBYear;
    People p1 = doQuerySci(Query);
    return p1;
}

Machines  SQLiteData::sortCompAlphaBack()
{
    string Query = selectAllComp + " " + orderByNameDe;
    Machines p1 = doQueryComp(Query);
    return p1;
}
Machines SQLiteData::sortCompBYear()
{

    string Query = selectAllComp + " " + orderByBYear;
    Machines p1 = doQueryComp(Query);
    return p1;

}

Machines SQLiteData::doQueryComp(const string que)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "ScientistsComputers.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    QString Q = QString::fromStdString(que);
    QSqlQuery queryname(db);
    queryname.exec(Q);
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
People SQLiteData::doQuerySci(const string que)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "ScientistsComputers.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    QString Q = QString::fromStdString(que);
    QSqlQuery queryname(db);
    queryname.exec(Q);
    People p1;
    while(queryname.next())
    {
        int id  = queryname.value("id").toUInt();
        string surname = queryname.value("surname").toString().toStdString();
        string name = queryname.value("name").toString().toStdString();
        char gender = queryname.value("gender").toChar().toLatin1();
        int byear  = queryname.value("byear").toUInt();
        int dyear  = queryname.value("dyear").toUInt();
        Individual i1(id,surname,name,gender,byear,dyear);
        p1.addIndi(i1);
    }
    db.close();
    return p1;
}

