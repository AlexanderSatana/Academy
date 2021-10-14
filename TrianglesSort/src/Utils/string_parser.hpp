#pragma once
#include <sstream>

template <typename T, typename ...Args>
bool ParseFromString(
    std::istringstream& line,
    char separator, 
    T& first,
    Args& ... rest)
{   
    std::string sub_string;
    std::getline(line, sub_string, separator);
    if (sub_string.size() <= 0)
    {
        return false;
    }

    std::istringstream(sub_string) >> first;
    if constexpr (sizeof...(rest) > 0)
    {
        return ParseFromString(line, separator, rest...);
    } 
    else {
        return true;
    }
}