#pragma once
#include <vector>
#include "OrderBookEntry.h"

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

        std::vector<OrderBookEntry> orders;
};