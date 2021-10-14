#pragma once
#include <vector>
#include "../Object/object.hpp"

class IDataDrawer
{
    public:
        virtual ~IDataDrawer() = default;
        virtual void Draw(const std::vector<std::unique_ptr<Object>>& objects) const = 0;
};