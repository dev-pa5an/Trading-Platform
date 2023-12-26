#include "CSVReader.h"
#include <iostream>

CSVReader::CSVReader()
{

}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFile)
{
    std::vector<OrderBookEntry> entries;
    return entries;
}


std::vector<std::string> CSVReader::tokenise(std::string csvLine, char seperator)
{

    std::vector<std::string> tokens;
    signed int start, end;
    std::string token;
    start = csvLine.find_first_not_of(seperator, 0);
    do
    {
        end = csvLine.find_first_of(seperator, start);
        
        if (start == csvLine.length() || start == end) break; //nothing more to find

        if (end >= 0) token = csvLine.substr(start, end - start); //we found the seperator
        else token = csvLine.substr(start, csvLine.length() - start);

        tokens.push_back(token);

        start = end + 1;

    }while(end != std::string::npos);

    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens)
{
    double price, amount;
    if (tokens.size() != 5)
    {
        std::cout << "Bad line" << std::endl;
        throw std::exception{};
    }
    //we have 5 tokens
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch(const std::exception& e)
    {
        std::cout << "bad float" << std::endl;
        throw;
    }
    OrderBookEntry obe{price,amount,tokens[0],tokens[1],OrderBookEntry::stringToOrderBookType(tokens[2])};
    return obe;
}