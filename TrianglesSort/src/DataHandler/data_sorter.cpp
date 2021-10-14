#include <algorithm>
#include "data_sorter.hpp"

void DataSorter::Handle(std::vector<std::unique_ptr<Object>>& objects) const
{
    std::sort(
        objects.rbegin(),
        objects.rend(), 
        [](auto& first, auto& second) 
        {
            return *first.get() < *second.get();
        }
    );
}