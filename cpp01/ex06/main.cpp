#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        Harl harl;
        std::string level = argv[1];
    
        harl.complain(level);
        return 0;
    }
    else
        std::cout << "Usage: ./harlFilter level"<< std::endl;
}