#pragma once
#include <string>
#include <set>
#include <memory>
#include <sstream>
#include <iostream>

using namespace std;


class IComparable
{
    public:
        IComparable() = default;
        virtual ~IComparable() = default;
        virtual std::string ToString() const = 0;
        virtual float Hash() const = 0;
        const bool operator<(const IComparable& other) const;
};

struct Compare 
{
    bool operator() (
        const unique_ptr<IComparable>&first, 
        const unique_ptr<IComparable>&second
        ) const
    {
        return *first < *second;
    }
};

using multiset_of_objects = multiset<
        unique_ptr<IComparable>, 
        Compare
    >;