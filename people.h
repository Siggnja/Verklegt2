#ifndef PEOPLE_H
#define PEOPLE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "people.h"
//#include "dataread.h"
#include "individual.h"
//const string FILENAME = "people.txt";

using namespace std;

class People
{
public:
    vector <Individual> getPerson() const;
    void addIndi(const Individual& i1);
    Individual getIndi(const int i) const;
    int getSize() const;
    //adds and individual to vector
    People(){};
    //default constructor

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
private:

    vector <Individual> person;
    /*

    void saveFile(const string filename);
    void swap(const int i, const int j);
    //saves individuals in vector to file
    bool checkIndiOrder(const Individual& i1, const Individual& i2);
    bool checkBirthYearOrder(const Individual& i1, const Individual& i2);
    bool checkDeathYearOrder(const Individual& i1, const Individual& i2);
    string makeLower(string& temp);
    //converts the string variable temp to all lower letters */
};

#endif // PEOPLE_H
