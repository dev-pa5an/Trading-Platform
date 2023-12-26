#include <fstream>
#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType {
    bid,
    ask
};

class OrderBookEntry {
public:
    OrderBookEntry(
        std::string timestamp,
        std::string product,
        OrderBookType orderType,
        double price,
        double amount)
        : timestamp_(timestamp),
          product_(product),
          orderType_(orderType),
          price_(price),
          amount_(amount) {}

public:
    std::string timestamp_;
    std::string product_;
    OrderBookType orderType_;
    double price_;
    double amount_;
};

std::vector<std::string> tokenise(std::string csvLine, char separator) {
    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(separator, 0);
    do {
        end = csvLine.find_first_of(separator, start);

        if (start == csvLine.length() || start == end) break; // nothing more to find

        if (end >= 0) 
            token = csvLine.substr(start, end - start); // we found the separator
        else 
            token = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(token);

        start = end + 1;
    } while(end != std::string::npos);

    return tokens;
}

int main() {
    std::ifstream csvFile{"20231224.csv"};

    if (csvFile.is_open()) {
        std::cout << "File is opened successfully" << std::endl;
        std::string line;
        std::vector<OrderBookEntry> orders;

        while (std::getline(csvFile, line)){
            try {
                std::vector<std::string> tokens = tokenise(line, ','); // Assuming comma is the separator
                double price = std::stod(tokens[3]);
                double amount = std::stod(tokens[4]);

                OrderBookType type;
                if (tokens[2] == "bid") {
                    type = OrderBookType::bid;
                } else if (tokens[2] == "ask") {
                    type = OrderBookType::ask;
                } else {
                    std::cerr << "Unknown order type: " << tokens[2] << std::endl;
                    continue; 
                }

                orders.push_back(OrderBookEntry{tokens[0], tokens[1], type, price, amount});
                std::cout << "Price is " << price << std::endl;
                std::cout << "Amount is " << amount << std::endl;
    
            }
            catch(const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                continue; 
            }
        }
    } else {
        std::cerr << "Failed to open file." << std::endl;
        return 1; // Exit with an error
    }   

    return 0;
}
