#include <iostream>
#include <list>
#include <string>
#include <set>
#include <iterator>
using namespace std;

class tiny_stock{
    private:

    public:
        string Name;
        string Industry;
        double Price;
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
};

void priceFit(tiny_stock ts, double priceMin, double priceMax){
    if( priceMax> ts.Price && ts.Price > priceMin){
        cout<<"The Name of stock is :"<< ts.Name << endl;
    }
}

void MarkCapFit(tiny_stock ts, double MarketCapMin, double MarketCapMax){
    if( MarketCapMax> ts.marketcap && ts.marketcap > MarketCapMin){
        cout<<"The Name of stock is :"<< ts.Name << endl;
    }
}

void ChangeFit(tiny_stock ts, double ChangeMin, double ChangeMax){
    if( ChangeMax> ts.change && ts.change > ChangeMin){
        cout<<"The Name of stock is :"<< ts.Name << endl;
    }
}

int main(){
    //Multiset will be sorted by price in ascending order
    struct priceStruct {
        bool operator() (tiny_stock const & lhs, tiny_stock const & rhs) const {
        return lhs.Price < rhs.Price;
        }
    };

    struct MarCapStruct {
        bool operator() (tiny_stock const & lhs, tiny_stock const & rhs) const {
        return lhs.marketcap < rhs.marketcap;
        }
    };

    struct ChangeStruct {
        bool operator() (tiny_stock const & lhs, tiny_stock const & rhs) const {
        return lhs.change < rhs.change;
        }
    };

    multiset<tiny_stock, priceStruct> myPrice;
    multiset<tiny_stock, MarCapStruct> myMarCap; 
    multiset<tiny_stock, ChangeStruct> myChange;

    //multiset<tiny_stock, priceStruct,MarCapStruct,ChangeStruct> myStocks;

    tiny_stock Apple = tiny_stock("APPL","Phone",100,30000,0.1);
    tiny_stock Banana = tiny_stock("Banana","Phone",1000,300000,0.2);
    tiny_stock Candice = tiny_stock("Candice","Phone",10000,3000000,0.3);
    tiny_stock Dodi = tiny_stock("Dodi","Phone",500,600000,0.15);

    //Insert values into multiset
    myPrice.insert(Apple);
    myPrice.insert(Banana);
    myPrice.insert(Candice);
    myPrice.insert(Dodi);

    myMarCap.insert(Apple);
    myMarCap.insert(Banana);
    myMarCap.insert(Candice);
    myMarCap.insert(Dodi);

    myChange.insert(Apple);
    myChange.insert(Banana);
    myChange.insert(Candice);
    myChange.insert(Dodi);

    
    int PerformSort = 0;
    do{
        cout<<"What sort u wanna perform? : \n1.askforPriceSort\n2.askforMarCapSort\n3.askforChangeSort\n4.quit"<<endl;
        cin>>PerformSort;
        //Copy multiset into a new one so that it gets sorted
        if(PerformSort==1){
            multiset<tiny_stock, priceStruct> myStocksSorted(myPrice.begin(), myPrice.end());
            
            //Verify that myStocksSorted is sorted by price in ascending order
            for(auto itr = myStocksSorted.begin(); itr != myStocksSorted.end(); ++itr)
                cout << itr->Name <<"  "<< itr->Price << endl;
            
            double Pmin, Pmax;
            cout<<"Price range: ";
            cin>>Pmin>>Pmax;
            for(auto itr = myStocksSorted.begin(); itr != myStocksSorted.end(); ++itr) {
            //The advantage of having sorted data structure is that we can exclude all stocks with prices greater than max
            //because they definitely will not fall within the range.
                if (itr->Price > Pmax) {
                    break;
                //For example, if max is 700, Banana and Candice will be ignored in this loop because we will break out of it when
                //we reach Banana.
                }
            priceFit(*itr, Pmin, Pmax);
            }
        }
        else if(PerformSort==2){
            multiset<tiny_stock, MarCapStruct> myStocksSorted(myMarCap.begin(), myMarCap.end());

            for(auto itr = myStocksSorted.begin(); itr != myStocksSorted.end(); ++itr)
                cout << itr->Name <<"  "<< itr->marketcap << endl;

            double Mmin, Mmax;
            cout<<"MarCap range: ";
            cin>>Mmin>>Mmax;

            for(auto itr = myStocksSorted.begin(); itr != myStocksSorted.end(); ++itr) {
            //The advantage of having sorted data structure is that we can exclude all stocks with prices greater than max
            //because they definitely will not fall within the range.
                if (itr->marketcap > Mmax) {
                    break;
                //For example, if max is 700, Banana and Candice will be ignored in this loop because we will break out of it when
                //we reach Banana.
                }
            MarkCapFit(*itr, Mmin, Mmax);
            }

        }
        else if(PerformSort==3){
            multiset<tiny_stock, ChangeStruct> myStocksSorted(myChange.begin(), myChange.end());

            for(auto itr = myStocksSorted.begin(); itr != myStocksSorted.end(); ++itr)
                cout << itr->Name <<"  "<< itr->change << endl;

            double Cmin, Cmax;
            cout<<"Change range: ";
            cin>>Cmin>>Cmax;

            for(auto itr = myStocksSorted.begin(); itr != myStocksSorted.end(); ++itr) {
            //The advantage of having sorted data structure is that we can exclude all stocks with prices greater than max
            //because they definitely will not fall within the range.
                if (itr->change > Cmax) {
                    break;
                //For example, if max is 700, Banana and Candice will be ignored in this loop because we will break out of it when
                //we reach Banana.
                }
            ChangeFit(*itr, Cmin, Cmax);
            }
        }
    }while(PerformSort !=4);
}