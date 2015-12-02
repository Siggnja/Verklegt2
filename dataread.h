#ifndef DATAREAD_H
#define DATAREAD_H

#include "people.h"
#include "ui.h"
#include "individual.h"
using namespace std;

class Dataread
{
public:
    Dataread(const string FILENAME);
    People readData();
    void addToFile(const Individual& i1);
    void removeFromFile(const People& p1, const Individual& i1);
private:
    string filename;
};

#endif // DATAREAD_H
