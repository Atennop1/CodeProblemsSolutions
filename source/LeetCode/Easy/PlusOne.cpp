#include <algorithm>
#include "Declarations.h"

namespace LeetCodeEasy
{
    std::vector<int> Solutions::PlusOne(std::vector<int> &digits)
    {
        std::vector<int> digits_copy = std::vector<int>(digits);
        int last_index = (int)digits_copy.size() - 1;

        for (int i = last_index; i > -1; i--)
        {
            digits_copy[i]++;

            if (digits_copy[i] % 10 != 0)
                break;

            digits_copy[i] = 0;
            if (i == 0)
            {
                std::reverse(digits_copy.begin(), digits_copy.end());
                digits_copy.push_back(1);
                std::reverse(digits_copy.begin(), digits_copy.end());
            }
        }

        return digits_copy;
    }
}