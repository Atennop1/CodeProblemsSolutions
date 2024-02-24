#include <valarray>
#include <cstdint>

namespace SixthKyu
{
    uint32_t AmountOfPages(uint32_t summary)
    {
        unsigned int result = 0;
        unsigned int digits_in_number_count = 1;

        while (summary != 0)
        {
            unsigned int number_of_digits = 9u * std::pow(10, digits_in_number_count - 1) * digits_in_number_count;

            if (summary >= number_of_digits)
            {
                result += number_of_digits / digits_in_number_count;
                summary -= number_of_digits;
                digits_in_number_count++;
                continue;
            }

            result += summary / digits_in_number_count;
            summary = 0;
        }

        return result;
    }
}