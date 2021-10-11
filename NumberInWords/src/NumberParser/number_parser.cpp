#include <algorithm>
#include <sstream>
#include <iostream>
#include "number_parser.hpp"


NumberParser::NumberParser()
{
    Init();
}

void NumberParser::Init()
{
    m_units = 
    {
        "нуль",
        "один",
        "два",
        "три",
        "чотири",
        "п'ять",
        "шість",
        "сім",
        "вісім",
        "дев'ять",
    };
    m_second_dozen = 
    {
        {"11", "одинадцять"},
        {"12", "дванадцять"},
        {"13", "тринадцять"},
        {"14", "чотирнадцять"},
        {"15", "п'тнадцять"},
        {"16", "шicтнадцять"},
        {"17", "сімнадцять"},
        {"18", "вiciмнадцять"},
        {"19", "дев'ятнадцять"}
    };
    m_dozens = 
    {
        "",
        "десять",
        "двадцять",
        "дридцять",
        "сорок",
        "п'ятдесят",
        "шістдесят",
        "сімдесят",
        "вісімдесят",
        "дев'яносто"
    };
    m_hundreds = 
    {
        "",
        "сто",
        "двісті",
        "триста",
        "чотириста",
        "п'ятсот",
        "шістсот",
        "сімсот",
        "вісімсот",
        "дев'ятсот"
    };
    m_power_of_1000_singular = 
    {
        "",
        "тисяча",
        "мільйон",
        "мільярд"
    };
    m_power_of_1000_plural = 
    {
        "",
        "тисячі",
        "мільйони",
        "мільярди"
    };
    m_power_of_1000_plural2 = 
    {
        "",
        "тисяч",
        "мільйонів",
        "мільярдів"
    };

}

void NumberParser::ParseNext3Digits(
    const std::string str,
    std::ostringstream& stream
    )
{
    if (str.size() == 1)
    {
        ParseNextDigit(str[0], stream);
        return;
    }
    if (str.size() == 2)
    {
        ParseNext2Digits(str, stream);
        return;
    }
    if (str[0] != '0')
    {
        stream << m_hundreds[str[0] - '0'] << ' ';
    }
    ParseNext2Digits(str.substr(1,2), stream);
}

void NumberParser::ParseNext2Digits(
    const std::string str,
    std::ostringstream& stream
    )
{

    if (m_second_dozen.find(str) != m_second_dozen.end())
    {
        stream << m_second_dozen[str] << ' ';

        return;
    }

    if (str[0] != '0')
    {
        stream  << m_dozens[str[0] - '0'] << ' ';
    }
    if (str[1] != '0')
    {
        stream  << m_units[str[1] - '0'] << ' ';
    }
}

void NumberParser::ParseNextDigit(
    const char digit_char,
    std::ostringstream& stream
    )
{
    if (digit_char != '0')
    {
        stream  << m_units[digit_char - '0'] << ' ';
    } else
    {
        if (stream.str().size() == 0) 
        {
            stream << m_units[digit_char - '0'];
        }
    }
}

std::string NumberParser::Parse(std::string number) 
{
    std::ostringstream stream_number;
    ParseMinus(number, stream_number);
    int end_index = number.size() % 3;
    int power_of_1000 = number.size() / 3 + (end_index!=0 ? 1 : 0) - 1;
    for (;power_of_1000 >= 0; end_index+=3, --power_of_1000)
    {
        uint16_t pos = std::max (0, end_index - 3);
        uint16_t len = end_index == 0 ? 3 : min (3, end_index);
        auto sub_str = number.substr(pos, len);
        ParseNext3Digits(sub_str, stream_number);

        ParsePowerOfThousand(
            sub_str,
            power_of_1000, 
            stream_number
        );
    }
    return stream_number.str();
}

std::string NumberParser::Parse(const char* number)
{
    return Parse(std::string(number));
}

void NumberParser::ParseMinus(
    std::string& str,
    std::ostringstream& stream
    )
{
    if (str.size() <= 0)
    {
        return;
    }
    if (str[0] == '-')
    {
        stream << "мiнус" << ' ';
        str = str.substr(1);
    }
}

void NumberParser::ParsePowerOfThousand(
    const std::string number_of_thousands,
    const uint16_t power,
    std::ostringstream& stream
    ) const 
{
    uint number_of_thousands_num;
    istringstream(number_of_thousands) >> number_of_thousands_num;
    if (number_of_thousands_num == 0)
    {
        return;
    }

    switch (number_of_thousands[number_of_thousands.size()-1])
    {
        case '1':
        {
            stream << m_power_of_1000_singular[power] << ' ';

            break;
        }
        case '2'...'4':
        {
            stream << m_power_of_1000_plural[power] << ' ';

            break;
        }
        default:
        {
            stream << m_power_of_1000_plural2[power] << ' ';
        }
    }
}