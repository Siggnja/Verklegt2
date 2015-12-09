#ifndef GLOBALCONSTANTS
#define GLOBALCONSTANTS

#include <iostream>
#include <string>

using namespace std;

//Below are constants used in the SQLiteData class when commands in SQLite are used

const string selectSci = "SELECT * FROM Scientist";
const string selectComp = "SELECT * FROM Computer";

const string selectAllSci = "SELECT * FROM Scientist as s WHERE s.deleted = 0";
const string selectAllComp = "SELECT * FROM Computer as s WHERE s.deleted = 0";
const string selectCount = "SELECT COUNT(*) AS COUNT FROM ";

const string createNewSci = "INSERT INTO Scientist(surname,name,gender,byear,dyear) VALUES ('";
const string createNewComp = "INSERT INTO Computer(name,byear,type) VALUES ('";
const string createNewRelation = "INSERT INTO Relation(scientist_id, computer_id) VALUES(";

const string updateSci = "UPDATE Scientist";
const string updateComp = "UPDATE Computer";
const string updateRel = "UPDATE Relation";

const string orderBySurname = "ORDER BY s.surname";
const string orderBySurnameDe = "ORDER BY s.surname DESC";
const string orderByName = "ORDER BY s.name";
const string orderByNameDe = "ORDER BY s.name DESC";
const string orderByBYear = "ORDER BY s.byear";
const string orderByDYear = "ORDER BY s.dyear";
const string orderByType = "ORDER BY s.type";

const string searchbYear = "AND s.byear=";
const string searchbYearFrom = " AND s.byear >";
const string searchbYearTo = "AND s.byear <";
const string searchdYear = "AND s.dyear=";
const string searchdYearFrom = " AND s.dyear >";
const string searchdYearTo = "AND s.dyear <";
const string searchGender = " AND s.gender ='";
const string searchName = "AND s.name LIKE '%";
const string searchOrName = "OR s.name LIKE '%";
const string searchSurname = "OR s.surname LIKE '%";
const string searchType = "AND s.type LIKE '%";
const string searchId = "AND s.id = ";

const string setBYear = "SET byear = ";
const string setDYear = "SET dyear = ";
const string setGender = "SET gender = '";
const string setName = "SET name = '";
const string setSurname = "SET surname = '";
const string setType = "SET type = '";
const string setDel = "SET deleted = 1";
const string setDel0 = "SET deleted = 0";

const string findId = "WHERE id = ";
const string findSciId = "WHERE scientist_id = ";
const string findCompId = "WHERE computer_id = ";
const string findNotDel = "WHERE deleted = 0";

const string selectAllDelSci = "SELECT * FROM Scientist as s WHERE s.deleted = 1";
const string selectAllDelComp = "SELECT * FROM Computer as s WHERE s.deleted = 1";
const string selectAllDelRel = "SELECT * FROM Scientist as s WHERE s.deleted = 1";


#endif // GLOBALCONSTANTS
