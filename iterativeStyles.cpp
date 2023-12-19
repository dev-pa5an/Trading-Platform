#include <iostream>
#include <string>
#include <vector>

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
                    OrderBookType orderType)
        : price(price),
        amount(amount),
        timestamp(timestamp), 
        product(product),
        orderType(orderType)
        {
            // Constructor body 
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
    //Define a vector named 'orders' to store instances of the 'OrderBookEntry' class.
    std::vector<OrderBookEntry> orders;

    //push an instance of the 'OrderBookEntry' class to the 'orders'
    orders.push_back(OrderBookEntry{23594,0.00000033,"2020/03/17 17:01:24.884492","DOGE/BTC",OrderBookType::ask});
    orders.push_back(OrderBookEntry{25000,0.00000078,"2020/03/18 17:01:24.884492","DOGE/BTC",OrderBookType::bid});
    orders.push_back(OrderBookEntry{25600,0.00000093,"2020/03/19 17:01:24.884492","DOGE/BTC",OrderBookType::ask});

    std::cout << orders[0].price << std::endl;

    for(OrderBookEntry order:orders)
    {
        std::cout << order.price << std::endl;
    }
    //using ampersand make it more efficint as it will directly reference to the object instead of copy it 
    for(OrderBookEntry& order:orders)
    {
        std::cout << order.price << std::endl;
    }

    for(unsigned int i=0;i<orders.size();++i)
    {
        std::cout << orders[i].price << std::endl;
    }
    for(unsigned int i=0; i<orders.size(); ++i)
    {
        std::cout << orders.at(i).price << std::endl;
    }

    return 0;
}