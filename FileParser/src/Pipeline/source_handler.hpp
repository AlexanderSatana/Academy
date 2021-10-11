#pragma once
#include "abstract_handler.hpp"

class SourceHandler : public AbstractHandler
{
    public:
        SourceHandler();
        ~SourceHandler() = default;
        void Handle(std::istream& stream) const override;
};