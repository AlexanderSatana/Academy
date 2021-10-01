#include <iostream>
#include <sstream>
#include <exception>
#include <stdexcept>
#include "data_reader.hpp"

uint DataReader::GetEnvelopeSide(const std::string& message)
{
    std::cout << message;
    //TODO: do while
    while(true) 
    {
        try
        {
            float side_length;
            
            std::string user_input_string;
            std::cin >> user_input_string;
            std::stringstream stream(user_input_string);
            stream >> side_length;
            //TODO: remake throught validation
            if (side_length <= 0) throw std::length_error("Invalid value. " + message);

            return side_length;
        } 
        catch (const std::length_error& exc)
        {
            std::cerr << exc.what() << std::endl;
        }
    }
}

uint DataReader::GetEnvelopeSide(const char* message) 
{
    return GetEnvelopeSide(std::string(message));
}
//TODO: IsContinue
bool DataReader::IfContinue()
{
    std::cout << "Enter [y | yes] to continue: ";
    std::string answer;
    std::cin >> answer;

    return answer == "y" || answer == "yes";
}