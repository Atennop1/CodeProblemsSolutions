#ifndef CPP_LEARNING_DECLARATIONS_LEETCODE_EASY_H
#define CPP_LEARNING_DECLARATIONS_LEETCODE_EASY_H

#include <vector>
#include <string>

namespace LeetCodeEasy
{
    class Solutions
    {
    public:
        static bool IsPalindrome(int x);
        static std::vector<int> TwoSum(std::vector<int> &numbers, int target);
        static std::string LongestCommonPrefix(std::vector<std::string> &strings);
        static std::vector<int> PlusOne(std::vector<int> &digits);
        static int RemoveElement(std::vector<int>& numbers, int removing_number);
        static std::string addBinary(const std::string& first, const std::string& second);
        static int RomanToInteger(const std::string &string);
        static int SingleNumber(const std::vector<int> &numbers);
        static uint32_t ReverseBits(uint32_t n);
        static int HammingWeight(uint32_t number);
    };
}

#endif
