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
    Individual(const string surnam, const string nam, const char gend, const int bir, const int dea);
    friend bool operator ==(const Individual& indi, const Individual& indi2);
    void setName(string str);
    void setSurname(string str);
    void setGender(char g);
    void setBirth(int i);
    void setDeath(int i);
    //void setId(int i);
    //Check if person already exists in database.
    string getName() const;
    string getSurname() const;
    char getGender() const;
    int getBirth() const;
    int getDeath() const;
    //int getId() const;
};

#endif // INDIVIDUAL_H
