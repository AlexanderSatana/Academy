#pragma once
#include <vector>
#include <memory>
#include "../Object/comparable.hpp"

using namespace std;

class ISourceReader 
{
    public:
        virtual ~ISourceReader() = default;
        virtual bool Ready() const = 0;
        virtual void Fill(multiset_of_objects& objects) const = 0;
};
