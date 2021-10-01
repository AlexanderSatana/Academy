#pragma once 


//TODO: use enum
template <typename T>
bool ConditionIsMet(T const& first, T const& second) 
{
    return first.CanBePutIn(second) || second.CanBePutIn(first);
}