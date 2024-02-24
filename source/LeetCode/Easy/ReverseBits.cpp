#include <bitset>
#include "Declarations.h"

namespace LeetCodeEasy
{
    uint32_t Solutions::ReverseBits(uint32_t number)
    {
        std::bitset<32> bits = std::bitset<32>(number);
        std::bitset<32> result = std::bitset<32>(0);

        for (int i = 0; i < 32; ++i)
        {
            if (bits[32 - 1 - i])
                result.set(i);
        }

        return (uint32_t)result.to_ullong();
    }
}