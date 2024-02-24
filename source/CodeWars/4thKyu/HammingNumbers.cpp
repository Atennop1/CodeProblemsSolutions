#include <algorithm>
#include "Declarations.h"

namespace FourthKyu
{
    uint64_t SumOfDivided::Hamber(const int n)
    {
        uint64_t hummings[n];
        unsigned int i = 0;
        unsigned int k = 0;
        unsigned int j = 0;

        uint64_t next_multiple_of_two = 2;
        uint64_t next_multiple_of_three = 3;
        uint64_t next_multiple_of_five = 5;
        uint64_t next_humming_number = 1;

        hummings[0] = 1;
        for (int counter = 1; counter < n; counter++)
        {
            next_humming_number = std::min(next_multiple_of_two,std::min(next_multiple_of_three, next_multiple_of_five));
            hummings[counter] = next_humming_number;

            if (next_humming_number == next_multiple_of_two)
            {
                i++;
                next_multiple_of_two = hummings[i] * 2;
            }

            if (next_humming_number == next_multiple_of_three)
            {
                j++;
                next_multiple_of_three = hummings[j] * 3;
            }

            if (next_humming_number == next_multiple_of_five)
            {
                k++;
                next_multiple_of_five = hummings[k] * 5;
            }
        }

        return next_humming_number;
    }
}