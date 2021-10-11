#pragma once
#include <array>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

#define NUMBER_OF_NUMS 10
#define MAX_POWER_OF_1000 3

class NumberParser
{
    public:
        NumberParser();
        virtual ~NumberParser() = default;
        std::string Parse(const char*);
        std::string Parse(std::string);

    protected:
        void Init();
        void ParseMinus(std::string&, std::ostringstream&);
        void ParseNext3Digits(const std::string, std::ostringstream&);
        void ParseNext2Digits(const std::string, std::ostringstream&);
        void ParseNextDigit(const char, std::ostringstream&);
        void ParsePowerOfThousand(const string, const uint16_t, ostringstream&) const;
        array<const char*, NUMBER_OF_NUMS> m_units;
        array<const char*, NUMBER_OF_NUMS> m_dozens;
        unordered_map<string, const char*> m_second_dozen;
        array<const char*, NUMBER_OF_NUMS> m_hundreds;
        array<const char*, MAX_POWER_OF_1000 + 1>  m_power_of_1000_singular;
        array<const char*, MAX_POWER_OF_1000 + 1>  m_power_of_1000_plural;
        array<const char*, MAX_POWER_OF_1000 + 1>  m_power_of_1000_plural2;
};