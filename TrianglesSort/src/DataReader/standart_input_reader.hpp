#pragma once
#include <memory>
#include "i_source_reader.hpp"

#define equals ==

class StandartInputReader : public ISourceReader
{
    public:
        StandartInputReader() {};
        ~StandartInputReader() = default;
        bool Ready() const override;
        void Fill(multiset_of_objects& objects) const override;

    private:
        bool AskToContinue() const;
};
