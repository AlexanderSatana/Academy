#include "replace_builder.hpp"
#include "source_handler.hpp"
#include "counter_handler.hpp"
#include "replace_handler.hpp"
#include "sink_handler.hpp"
#include "file_sink_handler.hpp"

ReplaceBuilder::ReplaceBuilder(
    const char* filepath, 
    const char* string_to_find, 
    const char* string_to_replace)
        : m_filepath(filepath),
        m_string_to_find(string_to_find),
        m_string_to_replace(string_to_replace) {}

unique_ptr<Pipeline> ReplaceBuilder::Build() const
{
    unique_ptr<Pipeline> pipeline = make_unique<Pipeline>();
    pipeline.get()->PushHandler(make_shared<SourceHandler>());
    pipeline.get()->PushHandler(make_shared<CounterHandler>(m_string_to_find));
    pipeline.get()->PushHandler(
        make_shared<ReplaceHandler>(m_string_to_find, m_string_to_replace)
    );
    pipeline.get()->PushHandler(make_shared<FileSinkHandler>(m_filepath));
    //pipeline.get()->PushHandler(make_shared<SinkHandler>(cout));
    
    return pipeline;
}