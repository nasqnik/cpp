#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

int fileError(std::string error, std::string filename);
bool openInputFile(std::ifstream &ifs, const std::string &filename);
bool openOutputFile(std::ofstream &ofs, const std::string &filename);


#endif