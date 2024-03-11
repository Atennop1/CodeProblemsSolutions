#include <valarray>
#include "../Declarations.h"

namespace LeetCodeNormal
{
    int Solutions::MyAtoi_2(const std::string &string)
    {
        long result = 0;
        int index = -1;
        int sign = 1;

        while (string[++index] == ' ') { }

        if (string[index] == '-')
            sign = -1;

        if (string[index] == '+' || string[index] == '-')
            index++;

        while (isdigit(string[index++]))
        {
            result = result * 10 + (string[index - 1] - '0');

            if (result > INT32_MAX)
                return (sign == 1 ? INT32_MAX : INT32_MIN);
        }

        return result * sign;
    }
}