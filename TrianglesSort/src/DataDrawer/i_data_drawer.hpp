#pragma once
#include <map>
#include "../Object/object.hpp"

using namespace std;

class IDataDrawer
{
    public:
        virtual ~IDataDrawer() = default;
        virtual void Draw(const multiset_of_objects& objects) const = 0;
};