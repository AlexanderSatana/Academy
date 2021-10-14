#pragma once
#include <string>
#include <memory>
#include <any>
#include <sstream>
#include <iostream>

class Object
{
    public:
        Object() = default;
        virtual ~Object() = default;
        virtual const std::string ToString() const = 0;
        virtual const float Hash() const = 0;
        const bool operator<(const Object& other) const;
};

