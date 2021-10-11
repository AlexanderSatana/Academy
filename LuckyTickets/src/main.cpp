#include <iostream>
#include "Utils/print_usage.hpp"
#include "Utils/get_file_name.hpp"
#include "Utils/validate.hpp"
#include "Ticket/method_parser.hpp"
#include "Ticket/ticket_counter.hpp"

int main(int argc, char* argv[])
{
    if (not Validated(argc, argv))
    {
        PrintUsage(argv[0]);

        return 0;
    }

    std::string filename = GetFileName();
    string error;
    shared_ptr<ITicketChecker> method_to_check_if_lucky;
    if (ParsedMethod(filename, method_to_check_if_lucky, error))
    {
        cout << error << endl;
        return 0;
    }

    TicketCounter ticket_counter(method_to_check_if_lucky);
    vector<int> tickets = {100100};
    auto number_of_lucky_tickets = ticket_counter.Count(100000, 999999);
    cout << "Number of \"lucky\" tickets: " << number_of_lucky_tickets
         << endl;

    return 0;
    
}