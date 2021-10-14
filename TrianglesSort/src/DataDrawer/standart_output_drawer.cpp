#include <iostream>
#include "standart_output_drawer.hpp"

void StandartOutputDrawer::Draw(const std::vector<std::unique_ptr<Object>>& objects) const 
{
    for (auto& object: objects) 
    {
        std::cout << object.get()->ToString() << std::endl;
    }
}

