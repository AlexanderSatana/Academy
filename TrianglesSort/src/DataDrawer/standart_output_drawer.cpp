#include <iostream>
#include "standart_output_drawer.hpp"

void StandartOutputDrawer::Draw(const multiset_of_objects& objects) const 
{
    for (auto r_it = objects.rbegin(); r_it!=objects.rend(); r_it++) 
    {
        std::cout << r_it->get()->ToString() << std::endl;
    }
}

