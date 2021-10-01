#include <iostream>
#include "DataReader/data_reader.hpp"
#include "ConditionChecker/condition_checker.hpp"
#include "Envelope/envelope.hpp"

int main() 
{
    do 
    {
        auto envelope_A_width    = DataReader::GetEnvelopeSide("Enter first envelope width: ");
        auto envelope_A_height   = DataReader::GetEnvelopeSide("Enter first envelope height: ");
        auto envelope_B_width    = DataReader::GetEnvelopeSide("Enter second envelope width: ");
        auto envelope_B_height   = DataReader::GetEnvelopeSide("Enter second envelope height: ");
        
        Envelope envelope_A{envelope_A_width, envelope_A_height};
        Envelope envelope_B{envelope_B_width, envelope_B_height};
        if (ConditionIsMet<Envelope>(envelope_A, envelope_B))
        {
            std::cout << "Yes, one of envelopes can be put in other"<< std::endl;
        } else
        {
            std::cout << "No, envelopes can not be put in each other"<< std::endl;
        }
    } while (DataReader::IfContinue());
}