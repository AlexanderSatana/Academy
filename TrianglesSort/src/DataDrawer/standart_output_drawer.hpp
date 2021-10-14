#pragma once
#include <memory>
#include "i_data_drawer.hpp"

class StandartOutputDrawer : public IDataDrawer
{
    public:
        void Draw(const std::vector<std::unique_ptr<Object>>& objects) const override;
};
