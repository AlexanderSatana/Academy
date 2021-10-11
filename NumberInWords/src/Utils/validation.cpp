#include <string>
#include <sstream>
#include "utils.hpp"

using namespace std;

bool Validate(int &argc, char* argv[])
{
    if (argc != 2)
    {
        return false;
    }
    string number(argv[1]);
    for (auto it = number.begin(); it != number.end(); ++it)
    {
        if (not std::isdigit(*it))
        {
            if (it == number.begin() and *it == '-')
            {
                continue;
            }
            return false;   
        }
    }

    return true;
}