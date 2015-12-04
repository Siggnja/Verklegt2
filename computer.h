#ifndef COMPUTER_H
#define COMPUTER_H

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
    /*
    int getId();
    int getYear();
    string getName();
    string getType();
    */



private:
    int id;
    int year;
    string name;
    string type;


};

#endif // COMPUTER_H
