#include "individual.h"

Individual::Individual() {

}

Individual::Individual(const string surnam, const string nam, const char gend, const int bir, const int dea)
{
    name = nam;
    surname = surnam;
    gender = gend;
    birth = bir;
    death = dea;
}

ostream& operator << (ostream& outs, Individual& id)
{
    outs << "Name: " << id.surname << ", " << id.name << endl;
    outs << "Gender: " << id.gender << endl;
    outs << "Year of birth: " << id.birth << endl;
    if (id.death == 0)
        outs << "The individual is still alive." << endl;
    else
        outs << "Year of death: " << id.death << endl;
    return outs;
}

bool operator == (const Individual& indi, const Individual& indi2)
{
    if (indi.birth == indi2.birth && indi.death == indi2.death && indi.surname == indi2.surname
       && indi.gender == indi2.gender && indi.name == indi2.name)
        return true;
    else
        return false;
}

istream& operator >> (istream& ins, Individual& id)
{
    cout << endl;
    char ans;
    cout << "Surname: ";
    getline(ins, id.surname);
    cout << "Given name: ";
    getline(ins, id.name);

    do{
        cout << "Gender (m/f): ";
        ins >> id.gender;
        if(id.gender != 'f' && id.gender != 'm' && id.gender != 'F' && id.gender != 'M')
            cout << "Invalid input, please try again!" << endl << endl;
    } while(id.gender != 'f' && id.gender != 'm' && id.gender != 'F' && id.gender != 'M');

    do {
        ins.clear();
        ins.ignore();
        cout << "Year of birth: ";
        ins >> id.birth;
        if(ins.fail())
            cout << endl << "Invalid input, please try again!" << endl << endl;
    } while(ins.fail());

    cout << "Is the individual alive?(y/n) ";
    cin >> ans;
    if (ans == 'n' || ans == 'N') {
        do {
            ins.clear();
            ins.ignore();
            cout << "Year of death: ";
            ins >> id.death;
            if(ins.fail()) {
                cout << endl << "Invalid input, please try again!" << endl << endl;
            }
            if(id.birth>id.death) {
                cout<<"Illegal deathyear! Input again: "<<endl<<endl;
            }
        } while(ins.fail()||id.birth>id.death);

        id.alive = 1;
    }
    else {
        id.death = 0;
        id.alive = 0;
    }    
    return ins;
}

string Individual::getName() const {
    return name;
}

string Individual::getSurname() const {
    return surname;
}

char Individual::getGender() const {
    return gender;
}

int Individual::getBirth() const {
    return birth;
}

int Individual::getDeath() const {
    return death;
}
