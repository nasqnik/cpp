#include "sed.hpp"

int fileError(std::string error, std::string filename)
{
    std::cerr << "Error: " << error << filename << std::endl;
    return 1;
}

bool openInputFile(std::ifstream &ifs, const std::string &filename)
{
    ifs.open(filename.c_str());
    if (!ifs)
    {
        fileError("could not open file ", filename);
        return false;
    }
    ifs.seekg(0, std::ios::end);
    if (ifs.tellg() == 0)
    {
        fileError("file is empty: ", filename);
        ifs.close();
        return false;
    }
    ifs.seekg(0, std::ios::beg);
    return true;
}

bool openOutputFile(std::ofstream &ofs, const std::string &filename)
{
    std::string newFilename = filename + ".replace";
    ofs.open(newFilename.c_str());
    if (!ofs)
    {
        fileError("could not create output file ", newFilename);
        return false;
    }
    return true;
}