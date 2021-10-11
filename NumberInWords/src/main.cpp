#include <iostream>
#include "Utils/utils.hpp"
#include "NumberParser/number_parser.hpp"

using namespace std;


int main(int argc, char* argv[])
{
    if (Validate(argc, argv))
    {
        auto number_in_words = NumberParser().Parse(argv[1]);
        std::cout << number_in_words << std::endl;
    } else 
    {
        PrintUsage(argv[0]);
    }
    
}