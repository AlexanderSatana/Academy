#pragma once
#include <memory>
#include "i_data_handler.hpp"

class DataSorter : public IDataHandler
{
    public:
        void Handle(std::vector<std::unique_ptr<Object>>& objects) const override;
};