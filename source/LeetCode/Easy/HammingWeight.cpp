#include <bitset>
#include "Declarations.h"

namespace LeetCodeEasy
{
    int Solutions::HammingWeight(uint32_t number)
    {
        std::bitset<32> bits = std::bitset<32>(number);
        int count = 0;

        for (int i = 0; i < 32; i++)
            count += (int)bits[i];

        return count;
    }
}