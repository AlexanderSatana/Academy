#include <algorithm>
#include <iostream>
#include <sstream>
#include "utils.hpp"

using namespace std;

bool IsPositiveNumber(const char*);

void PrintUsage(const char * prog_name) 
{
    cout << "Usage:" << endl
         << '\t' << prog_name << " N" << endl
         << "Print NaturalSequence of natural numbers whos square less than N"
         << endl;
}

bool Validated(int& argc, char* argv[])
{
    if (argc != 2 && argc != 3)
    {
        return false;
    }
    if (not IsPositiveNumber(argv[1]))
    { 
        return false;
    }
    if (argc == 3)
    {
        return IsPositiveNumber(argv[2]);
    }

    return true;
}

bool IsPositiveNumber(const char* line)
{
    string _line = line;

    return all_of(
        _line.begin(), 
        _line.end(), 
        [](const auto& c)
        {
            return isdigit(c);
        }
    );
}

uint32_t ParseNumber(const char* line)
{
    istringstream stream(line);
    uint32_t number;
    stream >> number;

    return number;
}