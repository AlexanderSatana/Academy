#pragma once
#include <string>
#include "i_canvas.hpp"

class StandartOutput : public ICanvas 
{
	public:
		StandartOutput() = default;
		void operator<<(std::string & str) const override;
		void operator<<(char str) const override;
};
