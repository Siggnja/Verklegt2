#ifndef GLOBALCONSTANTS
#define GLOBALCONSTANTS

#include <iostream>
#include <string>

using namespace std;

const string selectAllSci = "SELECT * FROM Scientist as s";
const string selectAllComp = "SELECT * FROM Computer as s";
const string noDel = "WHERE s.deleted =0 ";
const string orderBySurname = "ORDER BY s.surname";
const string orderBySurnameDe = "ORDER BY s.surname DESC";
const string orderByName = "ORDER BY s.name";
const string orderByNameDe = "ORDER BY s.name DESC";
const string orderByBYear = "ORDER BY s.byear";
const string orderByDYear = "ORDER BY s.dyear";
const string orderByType = "ORDER BY s.type";
const string searchbYear = "WHERE s.byear =";
const string searchbYearFrom = "WHERE s.byear >";
const string searchbYearTo = "AND s.byear <";




#endif // GLOBALCONSTANTS

