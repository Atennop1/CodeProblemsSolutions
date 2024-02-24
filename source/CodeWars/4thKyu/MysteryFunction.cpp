#include <valarray>
#include "Declarations.h"

namespace FourthKyu
{
    unsigned long Mystery(unsigned long n)
    {
        n++;
        int pow_of_two = 0;
        bool is_bigger_right = true;
        unsigned long result = 0;

        while (std::pow(2, pow_of_two) < n)
            pow_of_two++;

        for (int i = 0; i < pow_of_two; i++)
        {
            auto half = (unsigned long)std::pow(2, pow_of_two - i - 1);

            if (n <= half && is_bigger_right)
                continue;

            if ((n > half && is_bigger_right) || (n <= half && !is_bigger_right))
            {
                is_bigger_right = !is_bigger_right;
                result += half;
            }

            if (n > half)
                n -= half;
        }

        return result;
    }

    unsigned long MysteryInversion(unsigned long n)
    {
        int pow_of_two = 0;
        bool is_bigger_right = true;
        unsigned long result = 0;

        while (std::pow(2, pow_of_two) <= n)
            pow_of_two++;

        for (int i = 0; i < pow_of_two; i++)
        {
            auto half = (unsigned long)std::pow(2, pow_of_two - i - 1);

            if ((n >= half && is_bigger_right) || (n < half && !is_bigger_right))
                result += half;

            if (n >= half)
            {
                is_bigger_right = !is_bigger_right;
                n -= half;
            }
        }

        return result;
    }

    std::string NameOfMystery()
    {
        return "Gray code";
    }
}