//Implementations are here

#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry( double price,
                                double amount,
                                std::string timestamp, 
                                std::string product,
                                OrderBookType orderType)
:   price(price),
    amount(amount),
    timestamp(timestamp),
    product(product),
    orderType(orderType)
{

}

OrderBookType OrderBookEntry::stringToOrderBookType(std::string s)
{
    if (s == "bid")
    {
        return OrderBookType::bid;
    }
    if (s == "ask")
    {
        return OrderBookType::ask;
    }
    else
    {
        return OrderBookType::unknown;
    }
}