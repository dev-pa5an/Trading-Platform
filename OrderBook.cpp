#include "OrderBook.h"
#include "CSVReader.h"
#include <map>

OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}

std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;

    std::map<std::string, bool> prodMap;

    for (OrderBookEntry& e : orders)
    {
        prodMap[e.product] = true;
    }

    //now flatten the map to a vector of strings
    for (auto const& e : prodMap)
    {
        products.push_back(e.first);
    }

    return products;
}

std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, std::string product, std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;
    for (OrderBookEntry& e : orders)
    {
        if (e.orderType == type && e.product == product && e.timestamp == timestamp)
        {
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    double max = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (e.price > max) max = e.price;
    }
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double min = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (e.price < min) min = e.price;
    }
    return min;
}

std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string next_timestamp = "";
    for (OrderBookEntry& e : orders)
    {
        if (e.timestamp > timestamp)
        {
            next_timestamp = e.timestamp;
            break;
        }
    }
    if (next_timestamp == "")
    {
        next_timestamp = orders[0].timestamp;
    }
    return next_timestamp;
}

double OrderBook::getSpreadPrice(std::vector<OrderBookEntry>& orders)
{
    double spread = getHighPrice(orders) - getLowPrice(orders);
    return spread;
}

void OrderBook::insertOrder(OrderBookEntry& order)
{
    orders.push_back(order);
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}

std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
    //asks = OrderBook.asks
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask, product, timestamp);

    //bids = OrderBook.bids
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid, product, timestamp);

    //sales = []
    std::vector<OrderBookEntry> sales;

    //sort asks lowest first
    std::sort(asks.begin(),  asks.end(), OrderBookEntry::compareByPriceAsc);

    //sort bids highest first
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);

    //for ask in asks
    for (OrderBookEntry& ask : asks)
    {
        //for bid in bids
        for (OrderBookEntry& bid : bids)
        {
            if (bid.price >= ask.price)
            {
                OrderBookEntry sale{ask.price, 0, timestamp, product, OrderBookType::sale};

                if (bid.amount == ask.amount)
                {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0;
                    break;
                }
                if (bid.amount > ask.amount)
                {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = bid.amount - ask.amount;
                    break;
                }
                if (bid.amount < ask.amount)
                {
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    ask.amount = ask.amount - bid.amount;
                    bid.amount = 0;
                    continue; //some asks remain go to the next bid
                }
            }
            
        }
    }
    return sales;
}