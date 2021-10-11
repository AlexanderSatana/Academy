#pragma once
#include <memory>
#include <string>
#include "ticket.hpp"

using namespace std;

short ParsedMethod(const string&, shared_ptr<ITicketChecker>&, string&);