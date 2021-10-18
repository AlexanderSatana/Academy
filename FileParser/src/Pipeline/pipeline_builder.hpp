#pragma once
#include <memory>
#include "pipeline.hpp"

using namespace std;

class IPipelineBuilder
{
    public:
        virtual unique_ptr<Pipeline> Build() const = 0;
};