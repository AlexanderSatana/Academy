#pragma once
#include <map>
#include "../Object/object.hpp"

using namespace std;


class IDataHandler
{
    public:
        ~IDataHandler() = default;
        virtual void Handle(multiset_of_objects& objects) const = 0;
};
