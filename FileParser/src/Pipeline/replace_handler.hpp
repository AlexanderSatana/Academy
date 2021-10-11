#pragma once
#include "abstract_handler.hpp"

class ReplaceHandler : public AbstractHandler
{
    public:
        ReplaceHandler() = delete;
        ReplaceHandler(const std::string&, const std::string&);
        ~ReplaceHandler() = default;
        void Handle(std::istream& stream) const override;

    private:
        std::string m_string_to_find;
        std::string m_string_to_replace;
};