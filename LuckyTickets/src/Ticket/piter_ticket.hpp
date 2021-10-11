#pragma once
#include "ticket.hpp"

class PiterTicketChecker : public ITicketChecker
{
    public:
        bool IsLucky(uint) const override;
};