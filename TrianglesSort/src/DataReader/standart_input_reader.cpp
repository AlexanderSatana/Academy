#include "i_source_reader.hpp"
#include "standart_input_reader.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include "../Object/comparable.hpp"
#include "../Object/triangle.hpp"
#include "../Utils/string_parser.hpp"


bool StandartInputReader::Ready() const 
{
    return true;
}

void StandartInputReader::Fill(multiset_of_objects& objects) const
{
    std::string line;
    std::string name;
    bool        answer_succeded;
    float       a, b, c;

    do 
    {
        AskForEntities() ;
        std::getline(std::cin, line);     
        std::istringstream stream(line);
        bool parsed_successfully = ParseFromString<std::string, float, float, float>(stream, ',', name, a, b, c);
        bool params_are_valid = CheckForTriangleParameters(name, a, b, c);
        if (parsed_successfully && params_are_valid) 
        {
            objects.insert(make_unique<Triangle>(name, a, b, c));
        } else
        {
            std::cout << "Invalid input." << std::endl;
        }

        answer_succeded = AskToContinue();
    } while(answer_succeded);
}

void StandartInputReader::AskForEntities() const
{
    std::cout   << "Enter triangle name, side_a, side_b, side_c" 
                << std::endl;
}

bool StandartInputReader::AskToContinue() const
{
    std::string answer;   
    std::cout << "Whould you like to continue" << std::endl;
    std::getline(std::cin, answer);
    std::for_each(answer.begin(), answer.end(), [](char& c) { c = std::tolower(c);});
    
    return answer equals "yes" || answer equals "y";     
}