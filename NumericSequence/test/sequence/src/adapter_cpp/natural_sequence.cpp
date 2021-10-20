#include <iterator>
#include "natural_sequence.hpp"
#include "../../../../src/Sequence/natural_sequence.hpp"

NatSequence::NatSequence(uint num) 
{
	m_sequence = new NaturalSequence(num);
	count = 0;
}

uint NatSequence::Next()
{	
	auto iter = ((NaturalSequence*) m_sequence)->begin();
	for(auto i = 0; i < count; ++i)
	{
		++iter;
	}
	++count;
	return *iter;
}