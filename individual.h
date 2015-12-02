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
    char gender;    // f/F or m/M
    int birth, death;
    bool alive;
public:
    Individual();
    Individual(const string surnam, const string nam, const char gend, const int bir, const int dea);

    friend ostream& operator << (ostream& outs, Individual& id);
    friend istream& operator >> (istream& ins, Individual& id);
    friend bool operator ==(const Individual& indi, const Individual& indi2);
    //Check if person already exists in database.

    string getName() const;
    string getSurname() const;
    char getGender() const;
    int getBirth() const;
    int getDeath() const;
};

#endif // INDIVIDUAL_H
