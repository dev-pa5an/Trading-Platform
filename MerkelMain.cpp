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
    int input;

    currentTime = orderBook.getEarliestTime();

    while (true)
    {
        printMenu();
        input = getuserOption();
        processUserOption(input);
    }  
}

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

    std::cout << "Current time is " << currentTime << std::endl;
}

int MerkelMain::getuserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;   
    std::getline(std::cin, line);
    try
    {
        userOption = std::stoi(line);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

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
    for (std::string const& p : orderBook.getKnownProducts())
    {
        std::cout << "Product : " << p << std::endl;
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        std::cout << "Asks seen : " << entries.size() << std::endl;
        std::cout << "Max ask : " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask : " << OrderBook::getLowPrice(entries) << std::endl;

        std::cout << "Spread ask : " << OrderBook::getSpreadPrice(entries) << std::endl << std::endl;

    }

    // std::cout << "Order Book contains : " << orders.size() << std::endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for (OrderBookEntry& e : orders)
    // {
    //     if (e.orderType == OrderBookType::bid)
    //     {
    //         ++bids;
    //     }
    //     if (e.orderType == OrderBookType::ask)
    //     {
    //         ++asks;
    //     }
    // }
    // std::cout << "Total asks : " << asks << ", bids : "<< bids << std::endl;
}
void MerkelMain::enterAsk()
{
    std::cout << "Place an Ask: Enter details to make an ask on the exchange : product,price,amount, eg: ETH/BTC,5400,0.5" << std::endl;
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    
    if (tokens.size() != 3)
    {
        std::cout << "Bad input! " << input << std::endl;
    }
    else 
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(   tokens[1],
                                                    tokens[2],
                                                    currentTime,
                                                    tokens[0],
                                                    OrderBookType::ask);
        }
        catch(const std::exception& e)
        {
            std::cout << "MerkelMain::enterAsk Bad input!" << std::endl;
        }
        
        
    }

    std::cout << "You typed : " << input << std::endl << std::endl;
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
    currentTime = orderBook.getNextTime(currentTime);

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