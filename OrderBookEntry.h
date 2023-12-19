#pragma once 

#include <string>

//specifying a new data type for bid,ask
enum class OrderBookType{bid,ask}; 

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

        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};