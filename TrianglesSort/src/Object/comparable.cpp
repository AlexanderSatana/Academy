#include <sstream>
#include "comparable.hpp"

const bool IComparable::operator<(const IComparable& other) const 
{
    return this->Hash() < other.Hash();
}

