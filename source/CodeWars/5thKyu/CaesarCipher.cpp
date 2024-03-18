#include <vector>
#include <string>
#include "Declarations.h"

namespace FifthKyu
{
    std::vector<std::string> CaesarCipher::MovingShift(const std::string &string, int shift)
    {
        std::string coded_string;
        std::vector<std::string> result = { "", "", "", "", "" };

        for (char character : string)
        {
            coded_string += (char)(isalpha(character) ? ('A' + ((toupper(character) - 'A' + shift) % 26) + (islower(character) ? 'a' - 'A' : 0)) : character);
            shift = (shift == 25 ? 0 : shift + 1);
        }

        int fifth = ((int)coded_string.size() + 4) / 5;
        for (int i = 0; i != coded_string.size(); i++)
            result[i / fifth] += coded_string[i];

        return result;
    }

    std::string CaesarCipher::RemovingShift(std::vector<std::string> &strings, int shift)
    {
        std::string coded_string;
        for (const std::string &string : strings)
            coded_string += string;

        std::string result;
        for (char character : coded_string)
        {
            result += (char)(isalpha(character) ? ('A' + ((toupper(character) - 'A' + (26 - shift)) % 26) + (islower(character) ? 'a' - 'A' : 0)) : character);
            shift = (shift == 25 ? 0 : shift + 1);
        }

        return result;
    }
}