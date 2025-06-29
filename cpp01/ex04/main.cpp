#include "sed.hpp"

void replaceAndCopyLines(std::ifstream& ifs, std::ofstream& ofs, const std::string& s1, const std::string& s2)
{
    std::string line;
    while (std::getline(ifs, line))
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        ofs << line << std::endl;
    }
}

int copy(std::string& filename, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }

    std::ifstream ifs;
    if (!openInputFile(ifs, filename))
        return 1;
    std::ofstream ofs;
    if (!openOutputFile(ofs, filename))
        return 1;

    replaceAndCopyLines(ifs, ofs, s1, s2);

    ifs.close();
    ofs.close();
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        
        return copy(filename, s1, s2);
    }
    else
    {
        std::cout << "Usage: ./sed filename s1 s2" << std::endl;
        return 1;
    }
}