#include <iostream>
#include <memory>
#include "Utils/print_usage.hpp"
#include "DataReader/file_reader.hpp"
#include "DataReader/standart_input_reader.hpp"
#include "DataReader/i_source_reader.hpp"
#include "DataHandler/i_data_handler.hpp"
#include "DataDrawer/i_data_drawer.hpp"
#include "DataDrawer/standart_output_drawer.hpp"


int main(int argc, char* argv[]) 
{
    std::unique_ptr<ISourceReader> source_reader;
    std::unique_ptr<IDataDrawer> data_drawer;

    switch(argc) 
    {
        case 1:
        {
            source_reader = std::make_unique<StandartInputReader>();

            break;
        }
        case 2:
        {
            source_reader = std::make_unique<FileReader>(argv[1]);
            if (not source_reader.get()->Ready())
            {
                std::cerr   << "File \"" << argv[1]
                            << "\" not found." 
                            << std::endl;

                return 0;
            }

            break;
        }
        default:
        {
            PrintUsage(argv[0]);

            return 0;
        }
    }
    data_drawer = std::make_unique<StandartOutputDrawer>();
    multiset_of_objects objects;
    
    source_reader.get()->Fill(objects);
    data_drawer.get()->Draw(objects);
}