#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

class Individual
{
private:
    string name, surname;
    char gender;
    // f/F or m/M
    int birth, death;
    int id;
public:
    Individual();
    Individual(const int i,const string surnam, const string nam, const string gend, const int bir, const int dea);
    Individual(const string surnam, const string nam, const char gend, const int bir, const int dea);
    friend bool operator ==(const Individual& indi, const Individual& indi2);

    void setName(string str);
    void setSurname(string str);
    void setGender(char g);
    void setBirth(int i);
    void setDeath(int i);
    // These are the set functions, they are used to set the values of the private variables

    //void setId(int i);
    //Check if person already exists in database.

    string getName() const;
    string getSurname() const;
    char getGender() const;
    int getBirth() const;
    int getDeath() const;
    // These are the get functions, they are used to get the values of the private variables

    //int getId() const;
};

#endif // INDIVIDUAL_H
