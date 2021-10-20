#pragma once
#include <memory>
#include "sequence.hpp"

using namespace std;

unique_ptr<Sequence> GetSequence(int&, char*[]);
