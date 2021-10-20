#include <exception>
#include "get_sequence.hpp"
#include "natural_sequence.hpp"
#include "fibonacci_sequence.hpp"
#include "../Utils/utils.hpp"

unique_ptr<Sequence> GetSequence(int& argc, char* argv[]){
	switch (argc)
	{
		case 2:
		{
			uint32_t N = ParseNumber(argv[1]);

			return make_unique<NaturalSequence>(N);
		}
		case 3:
		{
			auto start_range = ParseNumber(argv[1]);
			auto end_range = ParseNumber(argv[2]);

			return make_unique<FibonacciSequence>(start_range, end_range);
		}
	}
}