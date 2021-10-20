#include "fibonacci_sequence.hpp"

FibonacciSequence::Iterator::Iterator()
{   
	m_current_num = 1;
	m_previous_num = 0;
}

FibonacciSequence::Iterator::Iterator(const uint32_t& init_num)
	: Iterator()
{   
	while (m_current_num < init_num)
	{
		++(*this);
	}
}

uint32_t FibonacciSequence::Iterator::operator* () const 
{
    return m_current_num;
}


bool FibonacciSequence::Iterator::operator== (
		const FibonacciSequence::Iterator& other
	) const
{
    return m_current_num == *other;
}

bool FibonacciSequence::Iterator::operator!= (
		const FibonacciSequence::Iterator& other
	) const
{
    return !(m_current_num == other.m_current_num);
}

FibonacciSequence::Iterator& FibonacciSequence::Iterator::operator++ ()
{
    m_current_num += m_previous_num;
	m_previous_num = m_current_num - m_previous_num;
    return *this;
}

FibonacciSequence::Iterator FibonacciSequence::Iterator::operator++ (int)
{
    ++(*this);
    return *this;
}

FibonacciSequence::FibonacciSequence(
	const uint32_t& init_n, 
	const uint32_t& end_n
	)
{
    Init(init_n, end_n);
}

void FibonacciSequence::Init(const uint32_t& init_n, const uint32_t& end_n) 
{
	m_start_number = init_n;
	m_end_number = end_n;
}

FibonacciSequence::Iterator FibonacciSequence::Iter() const 
{
    return Iterator(m_start_number);
}

void FibonacciSequence::Print(ostream& stream) const 
{
    for (auto it = Iter(); *it <= m_end_number; ++it)
    {
        stream << *it << ", ";
    }
    stream << endl;
}