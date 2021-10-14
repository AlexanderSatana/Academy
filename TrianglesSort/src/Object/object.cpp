#include <sstream>
#include "object.hpp"

const bool Object::operator<(const Object& other) const 
{
    return this->Hash() < other.Hash();
}

