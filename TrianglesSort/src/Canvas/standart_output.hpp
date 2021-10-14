#pragma once
#include "i_canvas.hpp"

class StandartOutput : public ICanvas 
{
    public:
        void operator<<(const std::string& string_to_draw) const override;
};
