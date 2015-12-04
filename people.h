#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "individual.h"

//const string FILENAME = "people.txt";

using namespace std;

class People
{
public:
    People();
    vector <Individual> getPerson() const;
    //returns the vector person
    void addIndi(const Individual& i1);
    //adds and individual to vector
    Individual getIndi(const int i) const;
    //returns an individual at person[i]
    int getSize() const;
    //returns the size of the vector
    bool checkBirthYearOrder(const Individual& i1, const Individual& i2);
    bool checkDeathYearOrder(const Individual& i1, const Individual& i2);
    //adds and individual to vector
    void removeIndi(string name);
    //removes an individual from the database, returns a new variable People
    //with a vector containing every individual except the removed one
    void swap(const int i, const int j);


    /*
    People(const string filename);
    People(const People& p1);
    //copy constructor

    People(const string filename);
    //returns the size of the vector

    friend ostream& operator << (ostream& outs, People& p1);
    Individual getIndi(const int i) const;
    //takes in two indexis of the person vector and swaps two individuals
    //who belong to these indexes in the vector */

    bool checkIndiOrder(const Individual& i1, const Individual& i2);
private:
    bool checkIndiOrder(const int i, const int j);
    vector <Individual> person;
    //saves individuals in vector to file


};
#endif // PEOPLE_H
