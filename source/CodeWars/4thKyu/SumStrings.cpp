#include <algorithm>
#include "Declarations.h"

namespace FourthKyu
{
    std::string SumStrings(const std::string &first, const std::string &second)
    {
        std::string result;
        int carry = 0;

        for (int i = 1; i <= int(first.length() > second.length() ? first.length() : second.length()); i++)
        {
            int digit = carry;

            if (int(first.length()) - i >= 0)
                digit += first[first.length() - i] - '0';

            if (int(second.length()) - i >= 0)
                digit += second[second.length() - i] - '0';

            result += std::to_string(digit % 10);
            carry = digit / 10;
        }

        if (carry == 1)
            result += '1';

        std::reverse(result.begin(), result.end());
        return result;
    }
}