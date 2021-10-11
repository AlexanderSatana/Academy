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
    std::istreambuf_iterator<char> end;
    std::string str_ = m_string_to_find + '\n';
    if (std::equal(start, end, str_.begin()))
    {
        std::istringstream next_stream(m_string_to_replace);
        m_next_handler.get()->Handle(next_stream);
    } else 
    {
        m_next_handler.get()->Handle(stream);
    }
}