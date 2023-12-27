#pragma once
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"

class MerkelMain
{
    public:
        MerkelMain();
        void init();

    private:
        void loadOrderBook();
        void printMenu();
        int getuserOption();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void processUserOption(int userOption);
        void enterBid();
        void printWallet();
        void goToNextWallet();

        OrderBook orderBook{"20231224.csv"};        
};