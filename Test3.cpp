#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Stock
{
    public:
        Stock(string sname, string sindustry, double sMarketCap){
            name = sname;
            industry = sindustry;
            MarketCap = sMarketCap;
        }
        Stock(const Stock &stok){
            name = stok.name;
            industry = stok.industry;
            MarketCap = stok.MarketCap;
        }
        ~Stock(){}
        string getName(){return name;}
        string getindustry(){return industry;}
        string getMarketCap(){return MarketCap;}

        bool operator==(const Stock &a1)
        {
            cout<<name<<" == "<<a1.name<<endl;
            if(name=a1.name){
                return true;
            }
            else
            {
                return false;
            }
        }
    private:
        string name;
        string industry;
        string MarketCap;
};

class Criteria
{
    public:
        Criteria(){}
        virtual ~Criteria(){}
        virtual vector<Stock> metCriteria(vector<Stock> &stocks)=0;
        static void printStocks(vector<Stock> &stocks);
};

void Criteria::printStocks(vector<Stock> &stocks)
{
    vector<Stock>::iterator it;
    for(it= stocks.begin(); it!= stocks.end();++it)
    {
        cout<<"stocks: ["<<"name: "<<(*it).getName()<<"industry:"<<(*it).getindustry()<<"MarketCap: "<<(*it).getMarketCap()<<"]"<<endl;
    }
}
class CriteriaMale : Criteria
{
    public:
        CriteriaMale(){}
        ~CriteriaMale(){}
        vector<Person>meetCriteria(vector<Person> &persons);
};
