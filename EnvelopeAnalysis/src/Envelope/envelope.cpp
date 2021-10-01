#include "envelope.hpp"
#include <algorithm>

Envelope::Envelope(uint w, uint h): m_width(w), m_height(h) {}

using namespace std;

bool Envelope::CanBePutIn(const Envelope& other) const 
{
    //TODO: max 80 chars in line
    return min(m_height, m_width) < min(other.GetHeight(), other.GetWidth()) 
            && max(m_width, m_height) < max(other.GetWidth(), other.GetHeight());
}

uint Envelope::GetWidth() const
{
    return m_width;
}

uint Envelope::GetHeight() const
{
    return m_height;
}