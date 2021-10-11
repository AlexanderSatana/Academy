#include <iostream>
#include <fstream>
#include <list>
#include "Pipeline/pipeline.hpp"
#include "Utils/print_usage.hpp"

using namespace std;

int main(int argc, char* argv[]) 
{
    Pipeline pipeline;
    switch (argc) 
    {
        case 3: 
        {
            Pipeline::BuildCounter(pipeline, argv[1], argv[2]);

            break;
        }
        case 4:
        {
            Pipeline::BuildReplacer(pipeline, argv[1], argv[2], argv[3]);

            break;
        }
        default: 
        {
            PrintUsage(cout, argv[0]);

            return 0;
        }
    }
    if (not pipeline.BuildSucceded())
    {
        cout << pipeline.Error() << endl;

        return 0;
    }
    std::ifstream stream(argv[1]);
    pipeline.Handle(stream);
    pipeline.Report(cout);
    stream.close();
}