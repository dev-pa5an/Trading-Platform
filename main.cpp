#include <iostream>
#include <string>
#include <vector>

void printMenu();
int getuserOption();
void printHelp();
void printMarketStats();
void enterAsk();
void processUserOption(int userOption);
void enterBid();
void printWallet();
void goToNextWallet();

//specifying a new data type for bid,ask
enum class OrderBookType{bid,ask}; 

//Define the class OrderBookEntry
class OrderBookEntry
{
    //Creating the constructor most efficint way
    OrderBookEntry( double _price,
                    double _amount,
                    std::string _timesamp,
                    std::string _product,
                    OrderBookType _orderType)
    :   price(_price),
        amount(_amount),
        timestamp(_timesamp),
        product(_product),
        orderType(_orderType)
    {

    }

    public:
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};

int main()
{
    //Declaring variables using vector
        std::vector<double> prices;
        std::vector<double> amounts;
        std::vector<std::string> timestamp;
        std::vector<std::string> product;
        std::vector<OrderBookType> orderType;
    
    while(true)
    {
        printMenu();
        int userOption = getuserOption();
        processUserOption(userOption);  
    }

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