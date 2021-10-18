#include <sstream>
#include "object.hpp"

const bool IObject::operator<(const IObject& other) const 
{
    return this->Hash() < other.Hash();
}

