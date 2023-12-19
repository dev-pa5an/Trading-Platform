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