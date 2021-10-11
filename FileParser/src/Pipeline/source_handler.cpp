#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include "source_handler.hpp"

//void SourceHandler::Handle(const std::string& string) const {}

SourceHandler::SourceHandler()
{

}

void SourceHandler::Handle(std::istream& stream) const
{
    stream.seekg(std::ios_base::beg);
    
    if (not m_next_handler.get()) 
    {
        return;
    }
        
    for (std::string line; getline(stream, line);)
    {
        line += '\n';
        auto line_stream = std::istringstream(line);
        if (m_next_handler.get())
        {
            m_next_handler.get()->Handle(line_stream);
        }
    }

}