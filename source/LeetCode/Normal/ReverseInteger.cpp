#include <algorithm>
#include <stdexcept>
#include "Declarations.h"

namespace LeetCodeNormal
{
    int Solutions::Reverse(int x)
    {
        if (x == 0)
            return 0;

        std::string string_integer = std::to_string(std::abs(x));
        std::reverse(string_integer.begin(), string_integer.end());

        for (int i = 0; i < string_integer.size(); i++)
        {
            if (string_integer[i] != '0')
                break;

            string_integer.erase(string_integer.begin() + i);
            i--;
        }

        if (x < 0)
        {
            std::reverse(string_integer.begin(), string_integer.end());
            string_integer.push_back('-');
            std::reverse(string_integer.begin(), string_integer.end());
        }

        try { return std::stoi(string_integer); }
        catch (std::out_of_range &e) { }

        return 0;
    }
}