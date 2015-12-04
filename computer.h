#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>

using namespace std;

class Computer
{
public:
    Computer();
    Computer(int idd, int yearr, string namee, string typee);

    void setId(int i);
    void setYear(int i);
    void setName(string str);
    void setType(string str);
    // These are the set functions, they are used to set the values of the private variables

    int getId() const;
    int getYear() const;
    string getName() const;
    string getType() const;
    // These are the getline functions, they are used to get the values of the private variables




private:
    int id;
    int year;
    string name;
    string type;
    // User typse in the types


};

#endif // COMPUTER_H
