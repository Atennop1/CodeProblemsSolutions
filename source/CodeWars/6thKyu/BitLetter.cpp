#include <vector>
#include <string>

namespace SixthKyu
{
    std::string BitLetter(const std::vector<unsigned char> &n)
    {
        constexpr unsigned char A_index = 'A';
        constexpr unsigned char lower_and_upper_difference = 'a' - 'A';
        std::string total_string;

        for (const unsigned char &letter: n)
        {
            unsigned char punctuation = letter >> 6;
            unsigned char capital = (letter >> 5) & 0x01;
            unsigned char letter_index = letter & 0x1F;

            if (punctuation == 1)
                total_string += ' ';

            total_string += (char)(letter_index + A_index + lower_and_upper_difference - (lower_and_upper_difference * capital));

            if (punctuation == 2)
                total_string += ',';

            if (punctuation == 3)
                total_string += '.';
        }

        return total_string;
    }
}