#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.h"

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
