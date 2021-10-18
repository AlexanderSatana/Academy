#include <iostream>
#include <fstream>
#include "Pipeline/pipeline_builder.hpp"
#include "Pipeline/counter_builder.hpp"
#include "Pipeline/replace_builder.hpp"
#include "Utils/print_usage.hpp"

using namespace std;


int main_() 
{
    int argc = 4;
    char * argv[] = 
    {
        "file-parser", 
        "../../data/war_and_peace.txt", 
        "XXII", 
        "REPLACED"
    };

    unique_ptr<IPipelineBuilder> builder;
    
    switch (argc) 
    {
        case 3: 
        {
            builder = make_unique<CounterBuilder>(argv[1], argv[2]);

            break;
        }
        case 4:
        {
            builder = make_unique<ReplaceBuilder>(argv[1], argv[2], argv[3]);

            break;
        }
        default: 
        {
            PrintUsage(cout, argv[0]);

            return 0;
        }
    }
    auto pipeline = builder.get()->Build();
    if (not pipeline.get()->BuildSucceded())
    {
        cout << pipeline.get()->Error() << endl;

        return 0;
    }  

    std::ifstream stream(argv[1]);
    pipeline.get()->Handle(stream);
    pipeline.get()->Report(cout);
    stream.close();
}