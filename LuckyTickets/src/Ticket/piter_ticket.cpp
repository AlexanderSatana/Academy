#include "piter_ticket.hpp"


bool PiterTicketChecker::IsLucky(uint ticket_number) const
{
    uint odd = 0;
    uint even = 0;
    while (ticket_number)
    {
        uint digit = ticket_number % 10;
        if (digit % 2)
        {
            ++even;
        } else
        {
            ++odd;
        }
        ticket_number /= 10;
    }
    
    return odd == even;
}