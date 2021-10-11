#include <algorithm>
#include <iostream>
#include "ticket_counter.hpp"

TicketCounter::TicketCounter(shared_ptr<ITicketChecker> ticket_checker)
    : m_ticket_checker(ticket_checker)
{

}

uint TicketCounter::Count(uint from, uint to) const 
{
    uint count = 0;
    for (uint num = from; num <= to; ++num)
    {
        if (m_ticket_checker.get()->IsLucky(num))
        {
            ++count;
        }
    }
    return count;
}

