#include "ticket.hpp"

class MoskowTicketChecker : public ITicketChecker
{
    public:
        bool IsLucky(uint) const override;
};