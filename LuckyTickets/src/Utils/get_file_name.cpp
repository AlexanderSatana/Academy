#include "get_file_name.hpp"
#include <iostream>
#include <string>

std::string GetFileName() 
{
    std::cout << "Enter file name with \"lucky\" tickets counting method:"
         << std::endl;
    std::string filename;
    std::getline(std::cin, filename);
    return filename;
}