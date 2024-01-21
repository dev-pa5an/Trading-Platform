#pragma once 

#include <string>

//specifying a new data type for bid,ask
enum class OrderBookType{bid,ask,unknown, sale}; 

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

        static bool compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2)
        {
            return e1.timestamp < e2.timestamp;
        }
        static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2)
        {
            return e1.price < e2.price;
        }
        static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2)
        {
            return e1.price > e2.price;
        }
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};