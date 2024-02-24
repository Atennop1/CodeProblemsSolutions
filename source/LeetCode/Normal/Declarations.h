#ifndef CPP_LEARNING_DECLARATIONS_LEETCODE_NORMAL_H
#define CPP_LEARNING_DECLARATIONS_LEETCODE_NORMAL_H

#include <vector>
#include <string>
#include <array>

namespace LeetCodeNormal
{
    class Solutions
    {
    public:
        struct ListNode
        {
            int value;
            ListNode *next;

            ListNode() : value(0), next(nullptr) { }
            explicit ListNode(int x) : value(x), next(nullptr) { }
            ListNode(int x, ListNode *next) : value(x), next(next) { }
        };

        static ListNode* AddTwoNumbers(ListNode *first, ListNode *second);
        static std::string IntToRoman(int number);
        static int Reverse(int x);
        static int Divide(int dividend, int divisor);
        static std::vector<std::string> LetterCombinations(const std::string& digits);
    };
}

#endif
