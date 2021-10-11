#include "validate.hpp"

bool Validated(int& argc, char* argv[])
{
    if (argc != 1)
    {
        return false;
    }

    return true;
}