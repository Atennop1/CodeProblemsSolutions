#include <cmath>
#include "Declarations.h"

namespace LeetCodeEasy
{
    bool Solutions::IsPalindrome(const int x)
    {
        if (x < 0)
            return false;

        int tenth_power = 0;
        int x_copy = x;

        while (x_copy != 0)
        {
            tenth_power++;
            x_copy /= 10;
        }

        for (int i = 0; i < (tenth_power + 1) / 2; ++i)
        {
            int first_digit = (x / (int)std::pow(10, i)) % 10;
            int last_digit = (x / (int)std::pow(10, tenth_power - 1 - i)) % 10;

            if (first_digit != last_digit)
                return false;
        }

        return true;
    }
}