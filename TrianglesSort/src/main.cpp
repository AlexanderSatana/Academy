#include <iostream>
#include <memory>
#include "DataReader/file_reader.hpp"
#include "DataReader/standart_input_reader.hpp"
#include "DataReader/i_source_reader.hpp"
#include "DataHandler/i_data_handler.hpp"
#include "DataHandler/data_sorter.hpp"
#include "DataDrawer/i_data_drawer.hpp"
#include "DataDrawer/standart_output_drawer.hpp"


void main(int argc, char* argv[]) 
{
    std::unique_ptr<ISourceReader> source_reader;
    std::unique_ptr<IDataHandler> data_handler;
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

                return;
            }
            break;
        }
        default:
        {
            std::cerr   << "Usage:" << std::endl
                        << argv[0] << " [ input-file ]" << std::endl
                        << "where:"
                        << "\n\tinput-file - file to handle"
                        << std::endl;

            return;
        }
    }
    data_handler = std::make_unique<DataSorter>();
    data_drawer = std::make_unique<StandartOutputDrawer>();

    std::vector<std::unique_ptr<Object>> objects;
    source_reader.get()->Fill(objects);
    data_handler.get()->Handle(objects);
    data_drawer.get()->Draw(objects);
}