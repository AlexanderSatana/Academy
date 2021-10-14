#pragma once
#include <vector>
#include "../Object/object.hpp"

class IDataHandler
{
    public:
        ~IDataHandler() = default;
        virtual void Handle(std::vector<std::unique_ptr<Object>>& objects) const = 0;
};
