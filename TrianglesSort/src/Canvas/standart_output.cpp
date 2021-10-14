#include <iostream>
#include "standart_output.hpp"

void StandartOutput::operator<<(const std::string& string_to_draw) const 
{
    std::cout << string_to_draw;
}