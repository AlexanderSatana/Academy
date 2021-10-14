#include <iterator>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include "file_sink_handler.hpp"

using namespace std;

FileSinkHandler::FileSinkHandler() 
{
    Init();
}

FileSinkHandler::FileSinkHandler(std::string filename) 
    : m_filename(filename)
{
    Init();
}

FileSinkHandler::~FileSinkHandler()
{
    Finalize();
}

void FileSinkHandler::Init() {
    //TODO: check if file exists
    m_filename_duplicate = m_filename + ".copy";
    m_ofstream = std::ofstream(m_filename_duplicate);
    if (m_ofstream.fail())
    {
        m_error_stream << "File \"" << m_filename << "\" "
            << "not found." << endl;
    }
}


void FileSinkHandler::Handle(std::istream& stream) const
{
    stream.seekg(std::ios_base::beg);
    std::ostringstream output;
    auto i_iter = istreambuf_iterator<char>{stream};
    std::istreambuf_iterator<char> end;
    auto o_iter = ostreambuf_iterator<char>{output};
    std::copy(i_iter, end, o_iter);
    m_ofstream << output.str();
    if (m_next_handler.get())
    {
        m_next_handler.get()->Handle(stream);
    }
}

void FileSinkHandler::Finalize() 
{
    m_ofstream.close();
    std::remove(m_filename.c_str());
    std::rename(m_filename_duplicate.c_str(), m_filename.c_str());
}

const bool FileSinkHandler::Ready() const
{
    //return m_ofstream.is_open() and not m_ofstream.fail() and not m_ofstream.failbit;
    return not m_ofstream.fail();
}