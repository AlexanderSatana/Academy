#pragma once

using uint = unsigned int;

struct NatSequence
{
	public:
		NatSequence(uint);
		uint Next();
	
	private:
		void* m_sequence;
		int count;
};