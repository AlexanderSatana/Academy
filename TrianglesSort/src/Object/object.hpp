#pragma once
#include <string>
#include <set>
#include <memory>
#include <sstream>
#include <iostream>

using namespace std;


class IObject
{
    public:
        IObject() = default;
        virtual ~IObject() = default;
        virtual std::string ToString() const = 0;
        virtual float Hash() const = 0;
        const bool operator<(const IObject& other) const;
};

struct Compare 
{
    bool operator() (
        const unique_ptr<IObject>&first, 
        const unique_ptr<IObject>&second
        ) const
    {
        return *first < *second;
    }
};

using multiset_of_objects = multiset<
        unique_ptr<IObject>, 
        Compare
    >;