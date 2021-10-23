#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){

    class Filter_list{

        double price;
        string industry;
        string Stockname;


        class Descriptive{
            double MarketCap,SharesOutstanding,FloatStocks,P_E,P_E_static,P_B,PS,Price_Cash_Flow_Ratio,Volume,NewHighNewLow,StockPrice,PercentChag,Bid_AskRatio = 0.0;

        };

        class Financial{
            double NetIncome, NetprofitGR,Revenue,RevenueGR,GrossProfitMargin,NetProfitMargin,Liability_AssetRatio,ROE = 0.0;

        };

        class Technical{
            double MA,EMA,KDJ,RSI,MACD,BOLL,BBI,SAR,AMOUNT,WMSR,MAVOL,TurnoverRate= 0.0;
        };

        class Profitability{
            double ROA_TTM,EBIT,OperatingMargin,OperatingProfit,ProfitToShareholders,NetProfitCashCover,ROIC,EBITDA,EBITDA_margin,FinancialExpensePercentage= 0.0;
        };

        class Liquidity{
            double CurrentRatio,QuickRatio= 0.0;
        };

        class CS{
            double CurrentAssetRatio,CurrentDebtRatio,EquityMultiplier,PropertyRatio,Cash_andCashEquivalents= 0.0;
        };

        class Efficiency{
            double OperatingCashFlow,TotalAssetTurnover,FixedAssetTurnover,InventoryTurnover,AccountsReceivable= 0.0;
        };

        class Growth{
            double EBITGR,TotalAssetsGR,ProfitToShareHoldersGR,ProfitBeforeTaxGR,EPSGR,ROEGR,ROICGR,NOCFGR,NOCFpershareGR= 0.0;
        };

        class CashFlow{
            double CFO,OP_EBT= 0.0;
        };

        class PerShare{
            double BasicEPS,DilutedEPS,NOCFpershare= 0.0;
        };
    };


    private:
        class Period{
            void Annual,Q1,Q9,interim,H1,D1,W1,M1,Y1,D5,Year,Month,Week,Day,Hour,Min;
        };

        double MarketCap,SharesOutstanding,FloatStocks,P_E,P_E_static,P_B,PS,Price_Cash_Flow_Ratio,Volume,NewHighNewLow,StockPrice,PercentChag,Bid_AskRatio;
        double NetIncome, NetprofitGR,Revenue,RevenueGR,GrossProfitMargin,NetProfitMargin,Liability_AssetRatio,ROE;
        double MA,EMA,KDJ,RSI,MACD,BOLL,BBI,SAR,AMOUNT,WMSR,MAVOL,TurnoverRate;
        double ROA_TTM,EBIT,OperatingMargin,OperatingProfit,ProfitToShareholders,NetProfitCashCover,ROIC,EBITDA,EBITDA_margin,FinancialExpensePercentage;
        double CurrentRatio,QuickRatio;
        double CurrentAssetRatio,CurrentDebtRatio,EquityMultiplier,PropertyRatio,Cash_andCashEquivalents；
        double OperatingCashFlow,TotalAssetTurnover,FixedAssetTurnover,InventoryTurnover,AccountsReceivable;
        double EBITGR,TotalAssetsGR,ProfitToShareHoldersGR,ProfitBeforeTaxGR,EPSGR,ROEGR,ROICGR,NOCFGR,NOCFpershareGR;
        double CFO,OP_EBT;
        double BasicEPS,DilutedEPS,NOCFpershare;

    return 0;
}