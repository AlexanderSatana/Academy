#pragma once
#include <iterator>
#include <vector>
#include <memory>
#include "ticket.hpp"

using namespace std;

class TicketCounter
{
    public:
        TicketCounter(shared_ptr<ITicketChecker>);
        uint Count(uint from, uint to) const;

    protected:
        shared_ptr<ITicketChecker> m_ticket_checker;
};