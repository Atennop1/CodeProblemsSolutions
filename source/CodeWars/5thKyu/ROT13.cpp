#include <string>

namespace FifthKyu
{
    std::string ROT13(const std::string &string)
    {
        std::string result;

        for (char character : string)
            result += (char)(isalpha(character) ? ('A' + ((toupper(character) - 'A' + 13) % 26) + (islower(character) ? 'a' - 'A' : 0)) : character);

        return result;
    }
}