#pragma once
#include "pipeline_builder.hpp"

class ReplaceBuilder : public IPipelineBuilder
{
    public:
        ReplaceBuilder(const char*, const char*, const char*);
        unique_ptr<Pipeline> Build() const override;

    private:
        string m_filepath;
        string m_string_to_find;
        string m_string_to_replace;
};