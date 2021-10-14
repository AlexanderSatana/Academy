#pragma once
#include <vector>
#include <memory>
#include "../Object/object.hpp"

class ISourceReader 
{
    public:
        virtual ~ISourceReader() = default;
        virtual const bool Ready() const = 0;
        virtual void Fill(std::vector<std::unique_ptr<Object>>& objects) const = 0;
};
