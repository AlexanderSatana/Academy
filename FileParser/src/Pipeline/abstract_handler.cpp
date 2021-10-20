#include <iostream>
#include "abstract_handler.hpp"

AbstractHandler::AbstractHandler() 
{
    Init();
}

void AbstractHandler::Init() 
{
}

void AbstractHandler::SetNextHandler(std::shared_ptr<IHandler> next)
{
    m_next_handler = next;
}

AbstractHandler::~AbstractHandler()
{
    Finalize();
}

void AbstractHandler::Handle(std::istream& stream) const
{
    if (not m_next_handler.get())
    {
        return;
    }
}

void AbstractHandler::Report(std::ostream& stream) const
{

}

bool AbstractHandler::Ready() const 
{
    return true;
}

string AbstractHandler::GetReport() const 
{
    return "";
}

string AbstractHandler::Error() const {
    return m_error_stream.str();
}

void AbstractHandler::Finalize()
{

}
