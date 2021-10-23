#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Person
{
    public:
        Person(string tname, string tgender, string tmaritalStatus){
            name = tname;
            gender=tgender;
            maritalStatus = tmaritalStatus;
        }
        Person(const Person &pson){
            name=pson.name;
            gender=pson.gender;
            maritalStatus=pson.maritalStatus;
        }
        ~Person(){}
        string getName(){ return name;}
        string getGender(){ return gender;}
        string getMaritalStatus(){return maritalStatus;}

        bool operator==(const Person &t1)
        {
            cout<<name<<" == "<<t1.name<<endl;
            if(name=t1.name){
                return true;
            }
            else
            {
                return false;
            }
        }
    private:
        string name;
        string gender;
        string maritalStatus;
};

class Criteria
{
    public:
        Criteria(){}
        virtual ~Criteria(){}
        virtual vector<Person> metCriteria(vector<Person> &persons)=0;
        static void printPersons(vector<Person> &persons);
};

void Criteria::printPersons(vector<Person> &persons)
{
    vector<Person>::iterator it;
    for(it= persons.begin(); it!= persons.end();++it)
    {
        cout<<"Persons: ["<<"name: "<<(*it).getName()<<"gender:"<<(*it).getGender()<<"maritalStatus: "<<(*it).getMaritalStatus()<<"]"<<endl;
    }
}
class CriteriaMale : Criteria
{
    public:
        CriteriaMale(){}
        ~CriteriaMale(){}
        vector<Person>meetCriteria(vector<Person> &persons);
};
