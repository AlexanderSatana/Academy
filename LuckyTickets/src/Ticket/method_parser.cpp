#include <iostream>
#include <fstream>
#include "method_parser.hpp"
#include "moskow_ticket.hpp"
#include "piter_ticket.hpp"

short ParsedMethod(
    const string& filename, 
    shared_ptr<ITicketChecker>& ticket_checker, 
    string& error
)
{
    ifstream file_stream;
    file_stream.exceptions(ios_base::failbit | ios_base::badbit);
    try
    {   
        file_stream.open(filename);
        string method;
        file_stream >> method;
        if (method == "Moskow")
        {
            ticket_checker = make_shared<MoskowTicketChecker>();
        }
        else if (method == "Piter")
        {
            ticket_checker = make_shared<PiterTicketChecker>();
        }
        else
        {
            error = "\"" + method + "\" - no such method.";

            return -1;
        }
    }
    catch(const std::exception& e)
    {
        error = "File \"" + filename + "\" not found.";

        return -1;
    }
    return 0;
}