#ifndef CPP_LEARNING_DECLARATIONS_6kyu_H
#define CPP_LEARNING_DECLARATIONS_6kyu_H

#include <vector>
#include <string>
#include <array>

namespace SixthKyu
{
    long FindMissing(std::vector<long> list);
    std::pair<std::size_t, std::size_t> TwoSum(const std::vector<int> &numbers, int target);
    std::string BitLetter(const std::vector<unsigned char> &n);
    unsigned int FruitMachine(const std::array<std::vector<std::string>, 3> &reels, const std::array<unsigned int, 3> &spins);
    std::string CreatePhoneNumber(const int array [10]);
    uint32_t IpToInt32(const std::string &ip);
    long long int LucasNumber(int n);
    int DeleteDigit(int number);
    uint32_t AmountOfPages(uint32_t summary);
    int Mobius(long long int n);
    std::string LastNonEmptyString(const std::string& str);
    int BreakTheWeb(int strength, int width);
    int Solve(const std::vector<int> &vector);
}

#endif
