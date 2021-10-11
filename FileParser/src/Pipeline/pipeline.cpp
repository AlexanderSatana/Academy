#include <algorithm>
#include <memory>
#include <sstream>
#include "pipeline.hpp"
#include "replace_handler.hpp"
#include "counter_handler.hpp"
#include "source_handler.hpp"
#include "sink_handler.hpp"
#include "file_sink_handler.hpp"

using namespace std;

void Pipeline::Handle(std::istream& stream) const
{
    m_handlers.front().get()->Handle(stream);
}


void Pipeline::PushHandler(std::shared_ptr<IHandler> handler) 
{
    if (m_handlers.back()) 
    {   
        m_handlers.back().get()->SetNextHandler(handler);
    }
    m_handlers.push_back(handler);
}

void Pipeline::Report(std::ostream& stream) const
{
    for (const auto& handler: m_handlers)  
    {
        handler.get()->Report(stream);
    }
}

void Pipeline::BuildCounter(
    Pipeline& pipeline,
    char* filepath, 
    char* string_to_count)
{
    pipeline.PushHandler(make_shared<SourceHandler>());
    pipeline.PushHandler(make_shared<CounterHandler>(string_to_count));
}

void Pipeline::BuildReplacer(
    Pipeline& pipeline,
    char* filepath, 
    char* string_to_find, 
    char* string_to_replace)
{
    pipeline.PushHandler(make_shared<SourceHandler>());
    pipeline.PushHandler(make_shared<CounterHandler>(string_to_find));
    pipeline.PushHandler(
        make_shared<ReplaceHandler>(string_to_find, string_to_replace)
    );
    pipeline.PushHandler(make_shared<FileSinkHandler>(filepath));
    pipeline.PushHandler(make_shared<SinkHandler>(cout));
}

const bool Pipeline::BuildSucceded() const 
{
    return std::all_of(
        m_handlers.begin(), 
        m_handlers.end(),
        [](auto ptr) 
        {
            return ptr.get()->Ready();
        }
    );
}

const std::string Pipeline::Error() const 
{
    std::ostringstream error_stream;
    for (const auto& handler: m_handlers)
    {
        if (not handler.get()->Ready())
        {
            error_stream << handler.get()->Error();
        }
    }
    return error_stream.str();
}