#include "iostream"
#include "print_usage.hpp"

using namespace std;

void PrintUsage(std::ostream& stream, const char* binary_name) 
{
    stream  << "Usage:" << endl
            << binary_name << " file-path string-to-count "
            << "[string-to-swap]" << endl;
}