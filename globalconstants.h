#ifndef GLOBALCONSTANTS
#define GLOBALCONSTANTS

#include <iostream>
#include <string>

using namespace std;

const string selectAllSci = "SELECT * FROM Scientist as s WHERE s.deleted = 0";
const string selectAllComp = "SELECT * FROM Computer as s";
const string orderBySurname = "ORDER BY s.surname";
const string orderBySurnameDe = "ORDER BY s.surname DESC";
const string orderByName = "ORDER BY s.name";
const string orderByNameDe = "ORDER BY s.name DESC";
const string orderByBYear = "ORDER BY s.byear";
const string orderByDYear = "ORDER BY s.dyear";
const string orderByType = "ORDER BY s.type";
const string searchbYear = "AND WHERE s.byear =";
const string searchbYearFrom = " AMDWHERE s.byear >";
const string searchbYearTo = "AND s.byear <";
const string searchdYear = "AND WHERE s.dyear =";
const string searchdYearFrom = " AND WHERE s.dyear >";
const string searchdYearTo = "AND s.dyear <";
const string searchGender = " AND WHERE s.gender =";




#endif // GLOBALCONSTANTS

