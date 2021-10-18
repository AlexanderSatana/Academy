#pragma once
#include <memory>
#include "i_data_drawer.hpp"

class StandartOutputDrawer : public IDataDrawer
{
    public:
        void Draw(const multiset_of_objects& objects) const override;
};
