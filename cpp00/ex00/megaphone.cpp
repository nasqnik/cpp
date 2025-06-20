#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j] != '\0'; j++)
            {
                if (std::isalpha(argv[i][j]))
                    std::cout << (char)std::toupper(argv[i][j]); // what is a static_cast?
                else
                    std::cout << argv[i][j];
            }
        }
    }
    std::cout << std::endl;
    return (0);
}