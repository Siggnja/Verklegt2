#include "dataread.h"
//tekur vid , eydir og les skjalid

Dataread::Dataread()
{
    filename = "people.txt";
}

People Dataread::readData(const string filename)
{
    People p1;
    ifstream ins;
    ins.open(filename.c_str());
    if(ins.fail())
    {
        cout << "Something went wrong while opening the file" << endl;
        exit(1);
    }
    string first ,last;
    int byear, dyear;
    char gender;
    while(getline(ins,last))
    {
        if(last == "\0")
        {
            getline(ins,last);
        }
        getline(ins,first);
        ins >> gender;
        ins >> byear;
        ins >> dyear;
        Individual i1(last,first,gender,byear,dyear);
        p1.addIndi(i1);
    }
    ins.close();
    return p1;
}
void Dataread::addToFile(const Individual& i1)
{

    ofstream outs;
    outs.open(filename.c_str(), ios::app);
    if(outs.fail())
    {
        cout << "Something went wrong with opening the output file" << endl;
        exit(1);
    }
    outs << endl;
    outs << i1.getSurname() << endl;
    outs << i1.getName() << endl;
    outs << i1.getGender() << endl;
    outs << i1.getBirth() << endl;
    outs << i1.getDeath();

    outs.close();
}
void Dataread::removeFromFile(const People& p1,const Individual& i1)
{
    //bool atBegin = true;
    People removed;
    for (int i = 0; i < p1.getSize(); i++)
    {
        if(!(p1.getIndi(i) == i1))
        {
            removed.addIndi(p1.getIndi(i));
        }
    }
    ofstream file;
    file.open(filename.c_str());
    for (int i = 0; i < removed.getSize()-1; i++)
    {
        //cout << atBegin << endl;

        file << removed.getIndi(i).getSurname() << endl;
        file << removed.getIndi(i).getName() << endl;
        file << removed.getIndi(i).getGender() << endl;
        file << removed.getIndi(i).getBirth() << endl;
        file << removed.getIndi(i).getDeath()<<endl;

    }
        file << removed.getIndi(removed.getSize()-1).getSurname() << endl;
        file << removed.getIndi(removed.getSize()-1).getName() << endl;
        file << removed.getIndi(removed.getSize()-1).getGender() << endl;
        file << removed.getIndi(removed.getSize()-1).getBirth() << endl;
        file << removed.getIndi(removed.getSize()-1).getDeath();
    file.close();
}
