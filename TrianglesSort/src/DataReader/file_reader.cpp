#include <iostream>
#include <sstream>
#include <fstream>
#include "file_reader.hpp"
#include "../Utils/string_parser.hpp"
#include "../Object/triangle.hpp"

using namespace std;

FileReader::FileReader(const std::string& filename) 
{
    m_input_file_stream = std::ifstream(filename);
}

const bool FileReader::Ready() const 
{
    return m_input_file_stream.is_open();
}

FileReader::~FileReader() 
{
    m_input_file_stream.close();
}

void FileReader::Fill(std::vector<std::unique_ptr<Object>>& objects) const
{
    std::string name;
    float a, b, c;

    for (std::string line; getline(m_input_file_stream, line); )
    {
        std::istringstream stream(line);
        bool parsed_successfully = ParseFromString<string, float, float, float>(stream, ',', name, a, b, c);
        bool params_are_valid = CheckForTriangleParameters(name, a, b, c);
        if (parsed_successfully && params_are_valid) 
        {
            objects.push_back(std::make_unique<Triangle>(name, a, b, c));
        }
    }
}