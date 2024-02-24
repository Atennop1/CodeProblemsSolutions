#include <string>

namespace SixthKyu
{
    std::string CreatePhoneNumber(const int array[10])
    {
        using std::to_string;

        return "(" + to_string(array[0]) + to_string(array[1]) + to_string(array[2]) + ") " +
            to_string(array[3]) + to_string(array[4]) + to_string(array[5]) + "-" +
            to_string(array[6]) + to_string(array[7]) + to_string(array[8]) + to_string(array[9]);
    }
}