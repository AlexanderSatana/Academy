#include "i_source_reader.hpp"
#include "standart_input_reader.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include "../Object/object.hpp"
#include "../Object/triangle.hpp"
#include "../Utils/string_parser.hpp"


const bool StandartInputReader::Ready() const 
{
    return true;
}

void StandartInputReader::Fill(std::vector<std::unique_ptr<Object>>& objects) const
{
    std::string line;
    std::string name;
    bool        answer_succeded;
    float       a, b, c;

    do 
    {
        std::cout << "Enter triangle name, side_a, side_b, side_c" 
                  << std::endl;
        std::getline(std::cin, line);     
        std::istringstream stream(line);
        bool parsed_successfully = ParseFromString<std::string, float, float, float>(stream, ',', name, a, b, c);
        bool params_are_valid = CheckForTriangleParameters(name, a, b, c);
        if (parsed_successfully && params_are_valid) 
        {
            objects.push_back(std::make_unique<Triangle>(name, a, b, c));
        } else
        {
            std::cout << "Invalid input." << std::endl;
        }

        answer_succeded = AskToContinue();
    } while(answer_succeded);
}

const bool StandartInputReader::AskToContinue() const
{
    std::string answer;   
    std::cout << "Whould you like to continue" << std::endl;
    std::getline(std::cin, answer);
    std::for_each(answer.begin(), answer.end(), [](char& c) { c = std::tolower(c);});
    
    return answer equals "yes" || answer equals "y";     
}