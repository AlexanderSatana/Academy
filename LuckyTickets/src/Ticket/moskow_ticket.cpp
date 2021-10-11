#include "moskow_ticket.hpp"

bool MoskowTicketChecker::IsLucky(uint ticket_number) const
{
    if (ticket_number < 100000 || ticket_number > 999999)
    {
        return false;
    }

    uint left_sum = 0;
    uint right_sum = 0;
    for (int i = 0; i < 3; ++i)
    {
        right_sum += ticket_number % 10;
        ticket_number /= 10;
    }
    for (int i = 0; i < 3; ++i)
    {
        left_sum += ticket_number % 10;
        ticket_number /= 10;
    }

    return left_sum == right_sum;
}