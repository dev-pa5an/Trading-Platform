#include "MerkelMain.h"
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"

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
    orders.push_back({23594, 0.00000033, "2020/03/17 17:01:24.884492", "DOGE/BTC", OrderBookType::ask});
    orders.push_back({25000, 0.00000078, "2020/03/18 17:01:24.884492", "DOGE/BTC", OrderBookType::bid});
    orders.push_back({25600, 0.00000093, "2020/03/19 17:01:24.884492", "DOGE/BTC", OrderBookType::ask});                       
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