#include <iterator>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <random>
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
    GenerateBackup();
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

bool FileSinkHandler::Ready() const
{
    //return m_ofstream.is_open() and not m_ofstream.fail() and not m_ofstream.failbit;
    return not m_ofstream.fail();
}

bool FileSinkHandler::FileExists(const string& filepath) const
{
    ifstream _fstream(filepath);
    return _fstream.good();
}

 void FileSinkHandler::GenerateBackup()
 {
     do 
     {
         m_filename_duplicate = m_filename + ".copy_" + GetRandomString();
     } while (FileExists(m_filename_duplicate));
 }

string FileSinkHandler::GetRandomString() const
{
    const uint8_t num_of_chars = 4;
    string alphabet =   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                        "abcdefghijklmnopqrstuvwxyz";
    string tmp_s;
    random_device rd;

    tmp_s.reserve(num_of_chars);
    for (auto i = 0; i < num_of_chars; ++i)
    {
        tmp_s += alphabet[rd() % sizeof(alphabet)];
    }

    return tmp_s;
}