#pragma once
#include <iostream>
#include <iterator> 

using namespace std;

class Sequence 
{
	public:
		Sequence() = default;
		virtual void Print(ostream& stream) const = 0;
};
