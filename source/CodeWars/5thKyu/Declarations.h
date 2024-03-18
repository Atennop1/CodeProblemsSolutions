#ifndef CPP_LEARNING_DECLARATIONS_5kyu_H
#define CPP_LEARNING_DECLARATIONS_5kyu_H

#include <vector>
#include <string>
#include <array>
#include <set>

namespace FifthKyu
{
    std::string Brainfuck(const std::string &code, const std::string &input);
    std::vector<int> MoveZeroes(const std::vector<int> &input);
    std::string IncrementString(const std::string &input);
    std::string Phone(const std::string &directory, const std::string &phone_number);
    std::string ROT13(const std::string &string);
    std::set<std::string> Check1800(const std::string &string);
    std::set<std::string> Check1800_2(const std::string &string);

    class CodeSquaredStrings
    {
    public:
        static std::string Code(const std::string &string);
        static std::string Decode(const std::string &string);
    };

    class CaesarCipher
    {
    public:
        static std::vector<std::string> MovingShift(const std::string &string, int shift);
        static std::string RemovingShift(std::vector<std::string> &string, int shift);
    };
}

#endif
