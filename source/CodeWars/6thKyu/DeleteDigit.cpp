#include <string>

namespace SixthKyu
{
    int DeleteDigit(int number)
    {
        std::string number_string = std::to_string(number);
        int max = 0;

        for (int i = 0; i < number_string.size(); ++i)
        {
            std::string string_copy = number_string;
            string_copy.erase(string_copy.begin() + i);

            if (std::stoi(string_copy) > max)
                max = std::stoi(string_copy);
        }

        return max;
    }
}