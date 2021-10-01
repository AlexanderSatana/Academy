#pragma once 
#include <string>

class DataReader 
{
    public:
        static bool IfContinue();
        static uint GetEnvelopeSide(const std::string& message);
        static uint GetEnvelopeSide(const char* message);
};
