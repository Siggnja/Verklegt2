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
        Individual i1(id,surname,name,gender,byear,dyear);
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
People SQLiteData::sortIndiAlphaFront()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "ScientistsComputers.sqlite";
    db.setDatabaseName(dbName);
    db.open();
    QSqlQuery queryname(db);
    queryname.exec("SELECT * FROM Scientist as s WHERE s.deleted =0 "
                   "ORDER BY s.surname");
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

Machines SQLiteData::sortCompAlphaFront()
{
    QSqlDatabase db;
    getDatabase();
    QSqlQuery queryname(db);
    queryname.exec("SELECT * FROM Computer as s WHERE s.deleted =0 "
                   "ORDER BY s.name");
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
void SQLiteData::getDatabase()
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "ScientistsComputers.sqlite";
    db.setDatabaseName(dbName);
    db.open();

}


vector<int> SQLiteData::getRelationsToComp(const int i)
{
    string querystring = "SELECT scientist_id FROM Relation AS s WHERE s.computer_id = ";
    querystring = querystring + int_to_string(i);
    vector<int> temp;

    QSqlDatabase db;
    getDatabase();
    QSqlQuery queryname(db);
    queryname.exec(QString::fromStdString(querystring));

    while(queryname.next())
    {
        /*int id  = queryname.value("id").toUInt();
        string name = queryname.value("name").toString().toStdString();
        string type = queryname.value("type").toString().toStdString();
        int byear  = queryname.value("byear").toUInt();
        Computer c1(id,byear,name,type);
        p1.addMach(c1);*/
        int sci_id = queryname.value("scientist_id").toUInt();

        temp.push_back(sci_id);

    }

    db.close();
    return temp;
}

string SQLiteData::int_to_string(int i)
{
    return QString::number(i).toStdString();
    /*
    string pi = "pi is " + QString::number(3.14159265358979323846264338).toStdString();
    string perfect = QString::number(1+2+4+7+14).toStdString() + " is a perfect number";
    cout << pi << '\n';
    cout << perfect << '\n';
    */
}
