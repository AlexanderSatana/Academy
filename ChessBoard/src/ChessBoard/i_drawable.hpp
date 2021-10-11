#pragma once
#include "../Canvas/i_canvas.hpp"

class IDrawable 
{
	public:
		virtual ~IDrawable() = default;
		virtual void Draw(const ICanvas& canvas) const = 0;
};
