#pragma once
#include <string>
#include <fstream>
#include <memory>
#include "i_source_reader.hpp"

class FileReader : public ISourceReader 
{
    public:
        FileReader() = default;
        FileReader(const std::string& filename);
        ~FileReader();
        const bool Ready() const override;
        void Fill(std::vector<std::unique_ptr<Object>>& objects) const override;

    private:
        mutable std::ifstream m_input_file_stream;
};
