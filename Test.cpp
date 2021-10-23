#include <iostream>
#include <list>
#include <string>
using namespace std;

//Object orientied programming

class Fitinto{
    virtual void FilterFit()=0;
};

class tiny_stock:Fitinto{
    private:


    public:
        string Name;
        string Industry;
        double Price,priceMin,priceMax;
        double marketcap,MarketCapMin,MarketCapMax;
        double change,ChangeMin,ChangeMax;

//simplify input process
        tiny_stock(string name,string industry,double price, double MarketCap,double Change){
            Name=name;
            Industry=industry;
            Price=price;
            marketcap=MarketCap;
            change=Change;
        }
//define price filter
        void FilterFit(){
            if( priceMax> Price   && Price > priceMin){
                cout<<"The Name is :"<<Name;
            }
        }
};



int main(){
//compress the input in certain format
    tiny_stock Apple = tiny_stock("APPL","Phone",100,30000,0.1);
    tiny_stock Banana = tiny_stock("Banana","Phone",1000,300000,0.2);
    tiny_stock Candice = tiny_stock("Candice","Phone",10000,3000000,0.3);
    tiny_stock Dodi = tiny_stock("Dodi","Phone",500,600000,0.15);

// I want to check all stocks in one shot instead of 1 at a time.
//
    cout<<"Price range: ";
    cin>>Apple.priceMin>>Apple.priceMax;
    Apple.FilterFit();

return 0;
}


