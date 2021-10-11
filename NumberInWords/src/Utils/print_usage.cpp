#include <iostream>
#include "utils.hpp"

using namespace std;

void PrintUsage(const string& prog_name) 
{
    cout << "Usage:" << endl
         << '\t' << prog_name << " number" << endl
         << "where:" << endl
         << "\tnumber - number to spell in words" << endl;
}

void PrintUsage(const char* prog_name) 
{
    PrintUsage(string(prog_name));
}