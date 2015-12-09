#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>

using namespace std;
//This Class holds a single Scientist/Individual and his values
class Individual
{
public:
    Individual();
    Individual(const string surnam, const string nam, const char gend, const int bir, const int dea);
    Individual(const int i, const string surnam, const string nam, const string gend, const int bir, const int dea);
    // Constructors with and without id -

    void setName(string str);
    void setSurname(string str);
    void setGender(char g);
    void setBirth(int i);
    void setDeath(int i);
    // These are the set functions, they are used to set the values of the private variables

    int getId() const;
    string getName() const;
    string getSurname() const;
    char getGender() const;
    int getBirth() const;
    int getDeath() const;
    // These are the get functions, they are used to get the values of the private variables

    friend bool operator == (const Individual& indi, const Individual& indi2);
    // Overloaded == operator, checks if individuals are the same

private:
    string name, surname;
    char gender;
    // f/F or m/M
    int birth, death;
    int id;
};

#endif // INDIVIDUAL_H
