#pragma once

using uint = unsigned int;

class ITicketChecker
{
    public:
        virtual bool IsLucky(uint) const = 0; 
};