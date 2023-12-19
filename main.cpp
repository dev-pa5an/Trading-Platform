#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"

void printMenu();
int getuserOption();
void printHelp();
void printMarketStats();
void enterAsk();
void processUserOption(int userOption);
void enterBid();
void printWallet();
void goToNextWallet();


int main()
{
    
    // while(true)
    // {
    //     printMenu();
    //     int userOption = getuserOption();
    //     processUserOption(userOption);  
    // }

    //Define a vector named 'orders' to store instances of the 'OrderBookEntry' class.
    std::vector<OrderBookEntry> orders;

    //push an instance of the 'OrderBookEntry' class to the 'orders'
    orders.push_back(OrderBookEntry{23594,0.00000033,"2020/03/17 17:01:24.884492","DOGE/BTC",OrderBookType::ask});

    std::cout << orders[0].price << std::endl;

    return 0;
}

void printMenu()
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

int getuserOption()
{
    std::cout << "Type in 1-6" << std::endl;   
    int userOption;
    std::cin >> userOption;
    std::cout << "You select " << userOption << std::endl;

    return userOption;
}
void printHelp()
{
    std::cout << "Help - choose options from the menu" << std::endl;
    std::cout << "and follow the on screen instructions." << std::endl;
}
void printMarketStats()
{
    std::cout << "Market looks good." << std::endl;
}
void enterAsk()
{
    std::cout << "Place an Ask: Enter details to make an ask on the exchange." << std::endl;
}
void enterBid()
{
    std::cout << "Place a Bid: Enter details to make a bid on the exchange." << std::endl;

}
void printWallet()
{
    std::cout << "Print Wallet: Display information about your wallet." << std::endl;

}
void goToNextWallet()
{
    std::cout << "Continue: Proceed to the next step." << std::endl;

}
void processUserOption(int userOption){

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