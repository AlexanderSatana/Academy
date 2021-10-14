#pragma once
#include <string>

class ICanvas
{
    public:
        ~ICanvas() = default;
        virtual void operator<<(const std::string& string_to_draw) const = 0;
};