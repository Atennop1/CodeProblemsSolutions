#include <string>
#include <bitset>
#include "Declarations.h"

namespace LeetCodeEasy
{
    std::string Solutions::addBinary(const std::string &first, const std::string &second)
    {
        if (first == "0" && second == "0")
            return "0";

        bool carry = false;
        std::bitset<10000> answer;

        std::bitset<10000> first_bitset = std::bitset<10000>(first);
        std::bitset<10000> second_bitset = std::bitset<10000>(second);

        for (int i = 0; i < 10000; i++)
        {
            bool sum = (first_bitset[i] ^ second_bitset[i]) ^ carry;
            carry = (first_bitset[i] && second_bitset[i]) || (first_bitset[i] && carry) || (second_bitset[i] && carry);
            answer[i] = sum;
        }

        std::string answer_string = answer.to_string();
        answer_string.erase(0, answer_string.find_first_not_of('0'));
        return answer_string;
    }
}