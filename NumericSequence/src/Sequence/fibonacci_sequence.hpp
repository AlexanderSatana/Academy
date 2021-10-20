#pragma once
#include "sequence.hpp"

class FibonacciSequence : public Sequence
{
	struct Iterator : public iterator<forward_iterator_tag, uint32_t>
    {
        public:
			Iterator();
            Iterator(const uint32_t&);
            uint32_t operator * () const;
            bool operator== (const Iterator& other) const;
            bool operator!= (const Iterator& other) const;
            Iterator& operator++ ();
            Iterator operator++ (int);

        private:
            uint32_t m_current_num;
			uint32_t m_previous_num;
    };

	public:
		FibonacciSequence(const uint32_t&, const uint32_t&);
		void Print(ostream&) const;

	private:
		Iterator Iter() const;
		void Init(const uint32_t&, const uint32_t&);
		uint32_t m_start_number;
		uint32_t m_end_number;
};