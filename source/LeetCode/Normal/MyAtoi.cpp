#include <valarray>
#include "Declarations.h"

namespace LeetCodeNormal
{
    int Solutions::MyAtoi(std::string string)
    {
        if (string.empty())
            return 0;

        int begin_index = -1;
        int end_index = 0;
        int multiplier = 1;

        while (!isdigit(string[end_index]) || isdigit(string[(end_index + 1 == string.length() ? end_index : end_index + 1)]))
        {
            if (isdigit(string[end_index]) && string[end_index] != '0' && begin_index == -1)
                begin_index = end_index;

            if (begin_index == -1 && (((string[end_index] == '+' || string[end_index] == '-') && end_index + 1 != string.length() && !isdigit(string[end_index + 1])) || isalpha(string[end_index]) || string[end_index] == '.'))
                return 0;

            if (end_index > 0 && isdigit(string[end_index]) && string[end_index - 1] == '-')
                multiplier = -1;

            if (end_index + 1 == string.length())
                break;

            end_index++;
        }

        if (isdigit(string[end_index]) && begin_index == -1)
            begin_index = end_index;

        if (end_index > 0 && isdigit(string[end_index]) && string[end_index - 1] == '-')
            multiplier = -1;

        int result = 0;
        int tenth_power = 0;
        begin_index = (begin_index == -1 ? end_index : begin_index);

        for (int i = end_index; i >= begin_index && i >= 0; i--, tenth_power++)
        {
            if (tenth_power > 9)
                return (multiplier == -1 ? INT32_MIN : INT32_MAX);

            if (!isdigit(string[i]))
                break;

            auto ten_in_power = (long long)std::pow(10, tenth_power);
            long long current_number = (long long)(string[i] - '0') * ten_in_power;

            if (current_number > INT32_MAX || ((long long)result + current_number) > INT32_MAX)
                return (multiplier == -1 ? INT32_MIN : INT32_MAX);

            result += (int)current_number;
        }

        return result * multiplier;
    }
}