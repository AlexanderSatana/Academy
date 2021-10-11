#include <algorithm>
#include <iterator>
#include <sstream>
#include "sink_handler.hpp"

using namespace std;

SinkHandler::SinkHandler(std::ostream& o_stream) 
{
    m_ostream = &o_stream;
}

void SinkHandler::Handle(std::istream& stream) const 
{
    stream.seekg(std::ios_base::beg);
    std::ostringstream output;
    auto i_iter = istreambuf_iterator<char>{stream};
    std::istreambuf_iterator<char> end;
    auto o_iter = ostreambuf_iterator<char>{output};
    std::copy(i_iter, end, o_iter);
    *m_ostream << output.str();
}