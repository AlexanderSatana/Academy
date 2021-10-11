#include <iostream>
#include "standard_ouput.hpp"

void StandartOutput::operator<<(std::string & str) const 
{
	std::cout << str;
}

void StandartOutput::operator<<(char str) const 
{
	std::cout << str;
}