#include "sqlitedata.h"


SQLiteData::SQLiteData()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "ScientistsComputers.sqlite";
    db.setDatabaseName(dbName);
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
People SQLiteData::sortIndiByDYear()
{
    string Query = selectAllSci + " " + orderByDYear;
    People p1 = doQuerySci(Query);
    return p1;

}
People SQLiteData::searchIndiByByear(const int year)
{
    string Query1 = selectAllSci + " " + searchbYear + int_to_string(year);
    string Query2 = selectAllSci + " " + searchbYearFrom + int_to_string(year-6) + " " + searchbYearTo + int_to_string(year+6);
    People p1 = doQuerySciOrOther(Query1, Query2);

    return p1;
}
People SQLiteData::searchIndiByDyear(const int year)
{
    string Query1 = selectAllSci + " " + searchdYear + int_to_string(year);
    string Query2 = selectAllSci + " " + searchdYearFrom + int_to_string(year-6) + " " + searchdYearTo + int_to_string(year+6);
    People p1 = doQuerySciOrOther(Query1, Query2);

    return p1;
}
People SQLiteData::searchIndiByGender(const char gender)
{
    string Query = selectAllSci + " " + searchGender +  gender + "'" + " " + orderBySurname;
    People p1 = doQuerySci(Query);
    return p1;

}
People SQLiteData::searchIndiByName(const string name)
{
    string Query = selectAllSci + " " + searchName + name + "%'" + " " + searchSurname +name + "%'";
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

Machines SQLiteData::sortCompByType()
{

    string Query = selectAllComp + " " + orderByType;
    Machines p1 = doQueryComp(Query);
    return p1;

}
Machines SQLiteData::searchCompByName(const string name)
{
    string Query = selectAllComp + " " + searchName + name + "%'" + orderByName;
    Machines p1 = doQueryComp(Query);
    return p1;
}
Machines SQLiteData::searchCompByByear(const int year)
{

}
Machines SQLiteData::searchCompByType(const string type)
{

}

Machines SQLiteData::doQueryComp(const string que)
{
    //QSqlDatabase db;
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbName = "ScientistsComputers.sqlite";
    //db.setDatabaseName(dbName);
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
    //QSqlDatabase db;
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbName = "ScientistsComputers.sqlite";
    //db.setDatabaseName(dbName);
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
        string gender = queryname.value("gender").toString().toStdString();
        int byear  = queryname.value("byear").toUInt();
        int dyear  = queryname.value("dyear").toUInt();
        Individual i1(id,surname,name,gender,byear,dyear);
        p1.addIndi(i1);
    }

    db.close();
    return p1;
}
People SQLiteData::doQuerySciOrOther(const string que1, const string que2)
{
    //QSqlDatabase db;
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbName = "ScientistsComputers.sqlite";
    //db.setDatabaseName(dbName);
    db.open();
    QString Q = QString::fromStdString(que1);
    QSqlQuery queryname(db);
    queryname.exec(Q);
    People p1;
    while(queryname.next())
    {
        int id  = queryname.value("id").toUInt();
        string surname = queryname.value("surname").toString().toStdString();
        string name = queryname.value("name").toString().toStdString();
        string gender = queryname.value("gender").toString().toStdString();
        int byear  = queryname.value("byear").toUInt();
        int dyear  = queryname.value("dyear").toUInt();
        Individual i1(id,surname,name,gender,byear,dyear);
        p1.addIndi(i1);
    }
    if(p1.getSize()==0)
    {

        Q =  QString::fromStdString(que2);
        queryname.exec(Q);
        while(queryname.next())
        {
            int id  = queryname.value("id").toUInt();
            string surname = queryname.value("surname").toString().toStdString();
            string name = queryname.value("name").toString().toStdString();
            string gender = queryname.value("gender").toString().toStdString();
            int byear  = queryname.value("byear").toUInt();
            int dyear  = queryname.value("dyear").toUInt();
            Individual i1(id,surname,name,gender,byear,dyear);
            p1.addIndi(i1);
        }

    }
    db.close();
    return p1;

}

void SQLiteData::getDatabase()
{
    //QSqlDatabase db;
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbName = "ScientistsComputers.sqlite";
    //db.setDatabaseName(dbName);
    db.open();

}

vector<int> SQLiteData::getRelationsToComp(const int i)
{
    string querystring = "SELECT scientist_id FROM Relation AS s WHERE s.computer_id = ";
    querystring = querystring + int_to_string(i);
    vector<int> temp;

    //QSqlDatabase db;
    getDatabase();
    QSqlQuery queryname(db);
    queryname.exec(QString::fromStdString(querystring));

    while(queryname.next())
    {
        int sci_id = queryname.value("scientist_id").toUInt();
        temp.push_back(sci_id);
    }

    db.close();
    return temp;
}

vector<int> SQLiteData::getRelationsToSci(const int i)
{
    string querystring = "SELECT computer_id FROM Relation AS s WHERE s.scientist_id = ";
    querystring = querystring + int_to_string(i);
    vector<int> temp;

    //QSqlDatabase db;
    getDatabase();
    QSqlQuery queryname(db);
    queryname.exec(QString::fromStdString(querystring));

    while(queryname.next())
    {
        int comp_id = queryname.value("computer_id").toUInt();
        temp.push_back(comp_id);
    }

    db.close();
    return temp;
}

string SQLiteData::int_to_string(int i)
{
    return QString::number(i).toStdString();
}


Individual SQLiteData::getSingleIndi(const int i)
{
    //QSqlDatabase db;
    //db = QSqlDatabase::addDatabase("QSQLITE");
    // dbName = "ScientistsComputers.sqlite";
    //db.setDatabaseName(dbName);
    db.open();

    string Query = selectAllSci + " WHERE s.id = " + int_to_string(i);
    QString Q = QString::fromStdString(Query);
    QSqlQuery queryname(db);
    queryname.exec(Q);
    queryname.next();

    int id  = queryname.value("id").toUInt();
    string surname = queryname.value("surname").toString().toStdString();
    string name = queryname.value("name").toString().toStdString();
     string gender = queryname.value("gender").toString().toStdString();
    int byear  = queryname.value("byear").toUInt();
    int dyear  = queryname.value("dyear").toUInt();
    Individual temp(id,surname,name,gender,byear,dyear);

    db.close();
    return temp;
}

Computer SQLiteData::getSingleComp(const int i)
{
    //QSqlDatabase db;
    //db = QSqlDatabase::addDatabase("QSQLITE");
    //QString dbName = "ScientistsComputers.sqlite";
    //db.setDatabaseName(dbName);
    db.open();

    string Query = selectAllComp + " WHERE s.id = " + int_to_string(i) + " AND s.deleted = 0";
    QString Q = QString::fromStdString(Query);
    QSqlQuery queryname(db);
    queryname.exec(Q);
    queryname.next();

    int id  = queryname.value("id").toUInt();
    string name = queryname.value("name").toString().toStdString();
    string type = queryname.value("type").toString().toStdString();
    int byear  = queryname.value("byear").toUInt();
    Computer temp(id,byear,name,type);

    db.close();
    return temp;
}
