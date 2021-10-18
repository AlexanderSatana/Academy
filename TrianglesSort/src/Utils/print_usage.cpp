#include <iostream>
#include "print_usage.hpp"

void PrintUsage(const char* prog_name)
{
    std::cerr   << "Usage:" << std::endl
                << prog_name << " [ input-file ]" << std::endl
                << "where:"
                << "\n\tinput-file - file to handle"
                << std::endl;
}