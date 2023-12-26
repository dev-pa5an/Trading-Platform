#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
#include "CSVReader.h"

MerkelMain::MerkelMain()
{

}

void MerkelMain::init()
{
    while (true)
    {
        loadOrderBook();
        printMenu();
        int input;
        input = getuserOption();
        processUserOption(input);
    }  
}

void MerkelMain::loadOrderBook()
{
    orders = CSVReader::readCSV("20231224.csv");                       
};

void MerkelMain::printMenu()
{
     // 1 print help
    std::cout << "1: Print help" << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats" << std::endl;
    // 3 make an offer
    std::cout << "3: Place an ask" << std::endl;
    // 4 make a bid 
    std::cout << "4: Place a bid" << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet" << std::endl;
    // 6 continue
    std::cout << "6: Continue" << std::endl;

    std::cout << "========================" << std::endl;
}

int MerkelMain::getuserOption()
{
    std::cout << "Type in 1-6" << std::endl;   
    int userOption;
    std::cin >> userOption;
    std::cout << "You select " << userOption << std::endl;

    return userOption;
}
void MerkelMain::printHelp()
{
    std::cout << "Help - choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions." << std::endl;
}
void MerkelMain::printMarketStats()
{
    std::cout << "Order Book contains : " << orders.size() << std::endl;
    unsigned int bids = 0;
    unsigned int asks = 0;
    for (OrderBookEntry& e : orders)
    {
        if (e.orderType == OrderBookType::bid)
        {
            ++bids;
        }
        if (e.orderType == OrderBookType::ask)
        {
            ++asks;
        }
    }
    std::cout << "Total asks : " << asks << ", bids : "<< bids << std::endl;
}
void MerkelMain::enterAsk()
{
    std::cout << "Place an Ask: Enter details to make an ask on the exchange." << std::endl;
}
void MerkelMain::enterBid()
{
    std::cout << "Place a Bid: Enter details to make a bid on the exchange." << std::endl;

}
void MerkelMain::printWallet()
{
    std::cout << "Print Wallet: Display information about your wallet." << std::endl;

}
void MerkelMain::goToNextWallet()
{
    std::cout << "Continue: Proceed to the next step." << std::endl;

}
void MerkelMain::processUserOption(int userOption){

    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterBid();
    }
    if (userOption == 4)
    {
        enterAsk();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        goToNextWallet();
    }
    if (userOption < 1 ||  userOption > 6)
    {
        std::cout << "Invalid Option - Please choose a number between 1-6" << std::endl;
    }
}