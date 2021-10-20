#include <iostream>
#include <cmath>
#include "natural_sequence.hpp"

using namespace std;

NaturalSequence::Iterator::Iterator(uint32_t num)
    : m_num(num)
{   
}

uint32_t NaturalSequence::Iterator::operator* () const 
{
    return m_num;
}


bool NaturalSequence::Iterator::operator== (const NaturalSequence::Iterator& other) const
{
    return m_num == *other;
}

bool NaturalSequence::Iterator::operator!= (const NaturalSequence::Iterator& other) const
{
    return m_num != other.m_num;
}

NaturalSequence::Iterator& NaturalSequence::Iterator::operator++ ()
{
    ++m_num;
    return *this;
}

NaturalSequence::Iterator NaturalSequence::Iterator::operator++ (int)
{
    ++m_num;
    return *this;
}

NaturalSequence::NaturalSequence(const uint32_t& num)
{
    Init(num);
}

void NaturalSequence::Init(uint32_t num) 
{
    auto sq_root = sqrt(num);
    float fract_part = sq_root - round(sq_root);
    m_last_number = uint32_t(sq_root);
    if (fract_part == 0.0)
    {
       --m_last_number;
    }
}

NaturalSequence::Iterator NaturalSequence::begin() const 
{
    return Iterator(m_start_number);
}

NaturalSequence::Iterator NaturalSequence::end() const
{
    return Iterator(m_last_number + 1);
}

void NaturalSequence::Print(ostream& stream) const 
{
    for (const auto number: *this)
    {
        stream << number << ", ";
    }
    stream << endl;
}