#include <iostream>
#include <memory>
#include "Utils/utils.hpp"
#include "Sequence/sequence.hpp"
#include "Sequence/get_sequence.hpp"

using namespace std;

int main(int argc, char * argv[])
{
    unique_ptr<Sequence> sequence;

    if (not Validated(argc, argv))
    {
        PrintUsage(argv[0]);

        return 0;
    }

    sequence = GetSequence(argc, argv);
    sequence->Print(cout);
    return 0;
}