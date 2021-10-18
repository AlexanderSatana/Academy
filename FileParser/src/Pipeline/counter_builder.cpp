#include "counter_builder.hpp"
#include "source_handler.hpp"
#include "counter_handler.hpp"
#include "replace_handler.hpp"
#include "sink_handler.hpp"
#include "file_sink_handler.hpp"

CounterBuilder::CounterBuilder(
    const char* filepath,
    const char* string_to_count
) : m_filepath(filepath), m_string_to_count(string_to_count){}

unique_ptr<Pipeline> CounterBuilder::Build() const 
{
    unique_ptr<Pipeline> pipeline = make_unique<Pipeline>();
    pipeline.get()->PushHandler(make_shared<SourceHandler>());
    pipeline.get()->PushHandler(make_shared<CounterHandler>(m_string_to_count));
    return pipeline;
}