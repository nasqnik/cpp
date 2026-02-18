#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {

    BitcoinExchange btc;
    
    if (argc != 2)
    {
        std::cout << "Usage: ./btc input.txt\n";
        return 1;
    }
    try {
        btc.parseData(argv[1]);
    }
    catch (const std::exception &e) {
        std::cout << e.what();
        return 1;
    }

    return 0;
}