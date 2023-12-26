#pragma once 

#include <string>

//specifying a new data type for bid,ask
enum class OrderBookType{bid,ask,unknown}; 

//Define the class OrderBookEntry
class OrderBookEntry
{
    public:
        // Constructor with member initialization list
        OrderBookEntry(double price,
                    double amount,
                    std::string timestamp, 
                    std::string product,
                    OrderBookType orderType);

        static OrderBookType stringToOrderBookType(std::string s);

        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};