#pragma once
#include  "abstract_handler.hpp"


class CounterHandler : public AbstractHandler
{
    public:
        CounterHandler() = delete;
        CounterHandler(std::string string_to_check);
        ~CounterHandler() = default;
        void Handle(std::istream& stream) const override;
        void Report(std::ostream& stream) const override;
    
    private:
        std::string GetReport() const override;
        std::string m_string_to_check;
        mutable uint32_t m_counter;
};