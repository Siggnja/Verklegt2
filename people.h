#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
//#include "dataread.h"
#include "individual.h"
//const string FILENAME = "people.txt";

using namespace std;

class People
{
public:
    People();
    vector <Individual> getPerson() const;
    void addIndi(const Individual& i1);
    Individual getIndi(const int i) const;
    int getSize() const;
    bool checkBirthYearOrder(const Individual& i1, const Individual& i2);
    bool checkDeathYearOrder(const Individual& i1, const Individual& i2);
    //adds and individual to vector
    void removeIndi(string name);
    void swap(const int i, const int j);
    //removes an individual from the database, returns a new variable People
    //with a vector containing every individual except the removed one

    /*
    People(const string filename);
    People(const People& p1);
    //copy constructor


    void addIndi(Individual& i1);
    //adds and individual to vector

    int getSize() const;
    //returns the size of the vector

    Individual getIndi(int i) const;
    //returns an individual at person[i]

    vector <Individual> getVector();
    //returns the vector person

    void removeIndi(string name);
    //removes an individual from the database, returns a new variable People
    //with a vector containing every individual except the removed one
    People(const string filename);
    //functions used to search for individuals in vector with specific traits:
    void searchName();
    void searchGender();
    void searchBirth();
    void searchDeath();
    //sort vector by the specified order:
    void sortAlpabetFront();
    void sortAlpabetBack();
    void sortByBirthYear();
    void sortByDeathYear();
    void sortByGender();
    //returns the size of the vector
    People removeIndi();
    //removes an individual from the database, returns a new variable People
    //with a vector containing every individual except the removed one
    friend ostream& operator << (ostream& outs, People& p1)

    friend ostream& operator << (ostream& outs, People& p1);
    Individual getIndi(const int i) const;
    //takes in two indexis of the person vector and swaps two individuals
    //who belong to these indexes in the vector
    void printVector(); */
    bool checkIndiOrder(const Individual& i1, const Individual& i2);
private:
    //void swap(const int i, const int j);
    bool checkIndiOrder(const int i, const int j);
    vector <Individual> person;
    //saves individuals in vector to file


};
#endif // PEOPLE_H
