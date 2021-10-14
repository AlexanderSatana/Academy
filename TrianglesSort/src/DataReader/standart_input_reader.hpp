#pragma once
#include <memory>
#include "i_source_reader.hpp"

#define equals ==

class StandartInputReader : public ISourceReader
{
    public:
        StandartInputReader() {};
        ~StandartInputReader() = default;
        const bool Ready() const override;
        void Fill(std::vector<std::unique_ptr<Object>>& objects) const override;

    private:
        const bool AskToContinue() const;
};
