#pragma once
#include <iostream>
#include "abstract_handler.hpp"

class SinkHandler : public AbstractHandler
{
    public:
        SinkHandler(std::ostream& o_stream);
        void Handle(std::istream& stream) const override;
    private:
        std::ostream* m_ostream;
};