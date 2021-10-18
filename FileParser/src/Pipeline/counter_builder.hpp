#pragma once
#include "pipeline_builder.hpp"

class CounterBuilder : public IPipelineBuilder
{
    public:
        CounterBuilder(const char*, const char*);
        unique_ptr<Pipeline> Build() const;

    private:
        string m_filepath;
        string m_string_to_count;
};