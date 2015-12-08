#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>
#include <string>

using namespace std;

class Individual
{
public:
    Individual();
    Individual(const int i,const string surnam, const string nam, const string gend, const int bir, const int dea);
    Individual(const string surnam, const string nam, const char gend, const int bir, const int dea);
    // Constructors with and without id

    friend bool operator == (const Individual& indi, const Individual& indi2);
    // Overloaded == operator, checks if individuals are the same

    void setName(string str);
    void setSurname(string str);
    void setGender(char g);
    void setBirth(int i);
    void setDeath(int i);
    // These are the set functions, they are used to set the values of the private variables

    string getName() const;
    string getSurname() const;
    char getGender() const;
    int getBirth() const;
    int getDeath() const;
    int getId() const;
    // These are the get functions, they are used to get the values of the private variables

private:
    string name, surname;
    char gender;
    // f/F or m/M
    int birth, death;
    int id;
};

#endif // INDIVIDUAL_H
