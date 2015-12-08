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

People SQLiteData::searchIndiByByear(const int year, bool& found)
{
    string Query1 = selectAllSci + " " + searchbYear + intToString(year);
    string Query2 = selectAllSci + " " + searchbYearFrom + intToString(year-6) + " " + searchbYearTo + intToString(year+6);
    People p1 = doQuerySciOrOther(Query1, Query2, found);
    return p1;
}

People SQLiteData::searchIndiByDyear(const int year, bool& found)
{
    string Query1 = selectAllSci + " " + searchdYear + intToString(year);
    string Query2 = selectAllSci + " " + searchdYearFrom + intToString(year-6) + " " + searchdYearTo + intToString(year+6);
    People p1 = doQuerySciOrOther(Query1, Query2, found);
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
    string Query = selectAllSci + " " + searchName + name + "%'" + " " + searchSurname + name + "%'" ;
    People p1 = doQuerySci(Query);
    if(p1.getSize() == 0)
    {
        Query = "SELECT (name ||' '||surname)AS expr1 FROM Scientist WHERE expr1 LIKE '%" + name + "%'";
        db.open();
        QString Q = QString::fromStdString(Query);
        QSqlQuery queryname(db);
        queryname.exec(Q);

        queryname.next();
        string newname = queryname.value("expr1").toString().toStdString();
        cout << newname;
        db.close();
        if(!newname.empty())
        {
            People p2 = sortIndiAlphaFront();
            for(int i = 0; i < p2.getSize(); i++)
            {
                string substr = p2.getIndi(i).getName() + " " + p2.getIndi(i).getSurname();
                if(newname == substr)
                {
                    p1.addIndi(p2.getIndi(i));
                }
            }
        }
    }
    return p1;
}

void SQLiteData::updateIndiName(const string name, const int id)
{
    string Query = updateSci + " " + setName + name + "'" + " " + findId + intToString(id);
    executeQuery(Query);
}

void  SQLiteData::updateIndiSurname(const string name, const int id)
{
    string Query = updateSci + " " + setSurname + name + "'" + " " + findId + intToString(id);
    executeQuery(Query);
}

void  SQLiteData::updateIndiBYear(const int year, const int id)
{
    string Query = updateSci + " " + setBYear + intToString(year) + " " + findId + intToString(id);
    executeQuery(Query);
}

void  SQLiteData::updateIndiDYear(const int year, const int id)
{
    string Query = updateSci + " " + setDYear + intToString(year) + " " + findId + intToString(id);
    executeQuery(Query);
}

void  SQLiteData::updateIndiGender(const char gender, const int id)
{
    string Query = updateSci + " " + setGender + gender + " '" + " " + findId + intToString(id);
    executeQuery(Query);
}

Machines SQLiteData::sortCompAlphaFront()
{
    string Query = selectAllComp + " " + orderByName;
    Machines p1 = doQueryComp(Query);
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

Machines SQLiteData::searchCompByByear(const int year, bool& found)
{
    string Query1 = selectAllComp + " " + searchbYear + intToString(year);
    string Query2 = selectAllComp + " " + searchbYearFrom + intToString(year-6) + " " + searchbYearTo + intToString(year+6);
    Machines p1 = doQueryCompOrOther(Query1, Query2, found);
    return p1;
}

Machines SQLiteData::searchCompByType(const string type)
{
    string Query = selectAllComp + " " + searchType + type + "%'";
    Machines p1 = doQueryComp(Query);
    return p1;
}

void SQLiteData::updateCompName(const string name, const int id)
{
    string Query = updateComp + " " + setName + name + "'" + " " + findId + intToString(id);
    executeQuery(Query);
}


void SQLiteData::updateCompType(const string type, const int id)
{
    string Query = updateComp + " " + setType + type + "'" + " " + findId + intToString(id);
    executeQuery(Query);
}

void SQLiteData::updateCompBYear(const int year, const int id)
{
    string Query = updateComp + " " + setBYear + intToString(year) + " " + findId + intToString(id);
    executeQuery(Query);
}

void SQLiteData::deleteComp(const int id)
{
    string Query = updateComp + " " + setDel + " " + findId + intToString(id);
    executeQuery(Query);
    deleteConnectionWithComp(id);
}

void  SQLiteData::deleteIndi(const int id)
{
    string Query = updateSci + " " + setDel + " " + findId + intToString(id);
    executeQuery(Query);
    deleteConnectionWithIndi(id);
}

void SQLiteData::addNewIndi(const Individual i1, bool& found)
{
    string Query1 = createNewSci + i1.getSurname() + "','" + i1.getName() + "','" + i1.getGender() + "'," + intToString(i1.getBirth()) + "," + intToString(i1.getDeath()) + ")";
    string Query2 = selectAllSci;
    People p1 = doQuerySci(Query2);
        found = false;
    int count = 0;
    for(int i = 0; i < p1.getSize(); i++)
    {
        if(i1 == p1.getIndi(i))
        {
            found = true;
            count = i;
            break;
        }
    }
    if(found)
    {
        string Query3 = updateSci + " " + setDel0 + " " + findId + intToString(p1.getIndi(count).getId());
        executeQuery(Query3);
    }
    else
    {
        executeQuery(Query1);
    }
    db.close();
}

void SQLiteData::addNewComp(const Computer c1, bool& found)
{
    string Query1 = createNewComp + c1.getName() + "'," + intToString(c1.getYear()) + ",'" + c1.getType() + "')";
    string Query2 = selectAllComp;
    Machines p1 = doQueryComp(Query2);
    found = false;
    int count = 0;
    for(int i = 0; i < p1.getSize(); i++)
    {
        if(c1 == p1.getComputer(i))
        {
            found = true;
            count = i;
            break;
        }
    }
    if(found)
    {
        string Query3 = updateComp + " " + setDel0 + " " + findId + intToString(p1.getComputer(count).getId());
        executeQuery(Query3);
    }
    else
    {
        executeQuery(Query1);
    }
    db.close();
}

Machines SQLiteData::doQueryComp(const string que)
{
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
        Computer c1(id, byear, name, type);
        p1.addMach(c1);
    }
    db.close();
    return p1;
}

People SQLiteData::doQuerySci(const string que)
{
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
        Individual i1(id, surname, name, gender, byear, dyear);
        p1.addIndi(i1);
    }
    db.close();
    return p1;
}

People SQLiteData::doQuerySciOrOther(const string que1, const string que2, bool& found)
{
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
        Individual i1(id, surname, name, gender, byear, dyear);
        p1.addIndi(i1);
    }
    if(p1.getSize() != 0)
    {
        found = true;
    }
    if(p1.getSize() == 0)
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
            Individual i1(id, surname, name, gender, byear, dyear);
            p1.addIndi(i1);
        }
    }
    db.close();
    return p1;
}

Machines SQLiteData::doQueryCompOrOther(const string que1, const string que2, bool& found)
{
    db.open();
    QString Q = QString::fromStdString(que1);
    QSqlQuery queryname(db);
    queryname.exec(Q);
    Machines p1;
    while(queryname.next())
    {
        int id  = queryname.value("id").toUInt();
        string name = queryname.value("name").toString().toStdString();
        string type = queryname.value("type").toString().toStdString();
        int byear  = queryname.value("byear").toUInt();
        Computer c1(id, byear, name, type);
        p1.addMach(c1);
    }
    if(p1.getSize() != 0)
    {
        found = true;
    }
    if(p1.getSize() == 0)
    {
        Q =  QString::fromStdString(que2);
        queryname.exec(Q);
        while(queryname.next())
        {
            int id  = queryname.value("id").toUInt();
            string name = queryname.value("name").toString().toStdString();
            string type = queryname.value("type").toString().toStdString();
            int byear  = queryname.value("byear").toUInt();
            Computer c1(id, byear, name, type);
            p1.addMach(c1);
        }
    }
    db.close();
    return p1;
}

void SQLiteData::executeQuery(const string query)
{
    db.open();
    QString Q = QString::fromStdString(query);
    QSqlQuery queryname(db);
    queryname.exec(Q);
}

vector<int> SQLiteData::getRelationsToComp(const int i)
{
    string querystring = "SELECT scientist_id FROM Relation AS s WHERE s.computer_id = ";
    querystring = querystring + intToString(i) + " AND s.deleted = 0";
    vector<int> temp;

    db.open();
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
    querystring = querystring + intToString(i) + " AND s.deleted = 0";
    vector<int> temp;

    db.open();
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

void SQLiteData::createConnection(const int idSci, const int idComp)
{
    string Query1 = createNewRelation + intToString(idSci) + ", " + intToString(idComp) + ")";
    string Query2 = updateRel + " " + setDel0 + " " + findSciId + intToString(idSci) + " AND computer_id = " + intToString(idComp);
    vector <int> Sci = getRelationsToComp(idSci);

    int count = Sci.size();
    executeQuery(Query1);
    Sci = getRelationsToComp(idSci);
    int size = Sci.size();

    if(count == size)
    {
        executeQuery(Query2);
    }
    db.close();
}

void SQLiteData::deleteConnectionWithIndi(const int idSci)
{
    string Query = updateRel + " " + setDel + " " + findSciId + intToString(idSci);
    executeQuery(Query);
}

void SQLiteData::deleteConnectionWithComp(const int idComp)
{
    string Query = updateRel + " " + setDel + " " + findCompId + intToString(idComp);
    executeQuery(Query);
}

void SQLiteData::deleteConnectionWithIndiAndComp(const int idSci, const int idComp)
{
    string Query = updateRel + " " + setDel + " " + findCompId + intToString(idComp) + "AND scientist_id = " +intToString(idSci);
    executeQuery(Query);
}

string SQLiteData::intToString(int i)
{
    return QString::number(i).toStdString();
}

Individual SQLiteData::getSingleIndi(const int i)
{
    string Query = selectAllSci + " " + searchId + intToString(i);
    People p1 = doQuerySci(Query);
    Individual temp = p1.getIndi(0);

    db.close();
    return temp;
}

Computer SQLiteData::getSingleComp(const int i)
{
    string Query = selectAllComp + " " + searchId + intToString(i);
    Machines c1 = doQueryComp(Query);
    Computer temp = c1.getComputer(0);

    db.close();
    return temp;
}

int SQLiteData::getDatabaseSize(const string temp)
{
    string que = selectCount + " " + temp + " " + findNotDel;

    db.open();
    QString Q = QString::fromStdString(que);
    QSqlQuery queryname(db);
    queryname.exec(Q);

    queryname.next();
    int size = queryname.value("COUNT").toUInt();

    db.close();
    return size;
}

bool SQLiteData::searchForId(const int id, const string tablename)
{
    string que = "SELECT * FROM " + tablename + " AS s " + findId + intToString(id);
    int var;

    db.open();
    QString Q = QString::fromStdString(que);
    QSqlQuery queryname(db);
    queryname.exec(Q);

    while(queryname.next())
    {
        var = queryname.value("id").toUInt();
    }
    db.close();

    if(var == id)
    {
        return true;
    }
    return false;
}
