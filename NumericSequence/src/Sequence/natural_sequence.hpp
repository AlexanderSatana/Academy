#pragma once
#include "sequence.hpp"

using namespace std;

class NaturalSequence : public Sequence
{
    struct Iterator : public iterator<forward_iterator_tag, uint32_t>
    {
        public:
            Iterator(uint32_t);
            uint32_t operator * () const;
            bool operator== (const Iterator& other) const;
            bool operator!= (const Iterator& other) const;
            Iterator& operator++ ();
            Iterator operator++ (int);

        private:
            uint32_t m_num;
    };

    public:
        NaturalSequence(const uint&);
        void Print(ostream&) const;
        Iterator begin() const;
        Iterator end() const;

    private:
        void Init(uint32_t num);
        const uint32_t m_start_number = 1;
        uint32_t m_last_number;
};