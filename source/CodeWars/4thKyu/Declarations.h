#ifndef CPP_LEARNING_DECLARATIONS_4kyu_H
#define CPP_LEARNING_DECLARATIONS_4kyu_H

#include <vector>
#include <string>

namespace FourthKyu
{
    class SumOfDivided
    {
    public:
        static uint64_t Hamber(int n);
        static std::string Return(const std::vector<int> &list);
    };

    unsigned long Mystery(unsigned long n);
    unsigned long MysteryInversion(unsigned long n);
    std::string NameOfMystery();

    std::string FormatDuration(int seconds);
    std::vector<int> Snail(const std::vector<std::vector<int>> &matrix);
    std::string SumStrings(const std::string &first, const std::string &second);
}

#endif
