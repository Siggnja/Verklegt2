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
public:
    Individual();
    Individual(const string surnam, const string nam, const char gend, const int bir, const int dea);
<<<<<<< HEAD
    friend bool operator ==(const Individual& indi, const Individual& indi2);
    /*
    friend ostream& operator << (ostream& outs, Individual& id);
    friend istream& operator >> (istream& ins, Individual& id);
=======

    friend bool operator == (const Individual& indi, const Individual& indi2);

    void setName(string str);
    void setSurname(string str);
    void setGender(char g);
    void setBirth(int i);
    void setDeath(int i);
>>>>>>> c3ecd5d30ff9ac479edaf836ed24bb2d316266e7

    //Check if person already exists in database.
    */
    string getName() const;
    string getSurname() const;
    char getGender() const;
    int getBirth() const;
    int getDeath() const;
};

#endif // INDIVIDUAL_H
