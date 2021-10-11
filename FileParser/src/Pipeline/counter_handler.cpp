#include <iterator>
#include <sstream>
#include "counter_handler.hpp"

CounterHandler::CounterHandler(std::string string_to_check)
{
    m_string_to_check = string_to_check;
    m_counter = 0;
}

void CounterHandler::Handle(std::istream& stream) const 
{
    stream.seekg(std::ios_base::beg);
    std::istreambuf_iterator<char> begin{stream};
    if (std::equal(m_string_to_check.begin(), m_string_to_check.end(), begin))
    {
        m_counter++;
    }
    if (m_next_handler.get())
    {
        m_next_handler.get()->Handle(stream);
    }
}

void CounterHandler::Report(std::ostream& stream) const
{
    stream << GetReport() << std::endl;
}

std::string CounterHandler::GetReport() const 
{
    std::ostringstream report;
    report  << "Found "
            << m_counter << " lines \""
            << m_string_to_check << '\"';
    return report.str();
}