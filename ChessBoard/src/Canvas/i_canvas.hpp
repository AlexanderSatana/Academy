#pragma once 
#include <string>

class ICanvas
{
	public:
		virtual ~ICanvas() = default;
		virtual void operator<<(std::string & str) const = 0;
		virtual void operator<<(char str) const = 0;
};
