#include <iostream>
#include "print_usage.hpp"

using namespace std;

void PrintUsage(const char* prog_name)
{
    cout << "Usage:" << endl
         << "\t" << prog_name << endl
         << "Find number of \"lucky\" tickets"
         << endl;
}