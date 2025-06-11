#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    j = 0;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (argv[i])
        {
            j = 0;
            while (argv[i][j])
            {
                if (std::isalpha(argv[i][j]))
                    std::cout << (char)std::toupper(argv[i][j]);
                else
                    std::cout << argv[i][j];
                j++;
            }
            if (i < argc - 1)
                std::cout << " ";
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}