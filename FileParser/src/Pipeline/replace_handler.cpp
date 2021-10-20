#include <iterator>
#include <sstream>
#include <iostream>
#include "replace_handler.hpp"

ReplaceHandler::ReplaceHandler(
    const std::string& string_to_find, 
    const std::string& string_to_replace)
{
    m_string_to_find = string_to_find;
    m_string_to_replace = string_to_replace + '\n';
}

void ReplaceHandler::Handle(std::istream& stream) const 
{
    stream.seekg(std::ios_base::beg);
    std::istreambuf_iterator<char> start{stream};
    if (std::equal(m_string_to_find.begin(), m_string_to_find.end(), start))
    {
        std::istringstream next_stream(m_string_to_replace);
        m_next_handler.get()->Handle(next_stream);
    } else 
    {
        m_next_handler.get()->Handle(stream);
    }
}