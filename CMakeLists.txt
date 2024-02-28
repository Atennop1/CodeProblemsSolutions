cmake_minimum_required(VERSION 3.25)
project(CodeProblemsSolutions)

set(CMAKE_CXX_STANDARD 11)

add_executable(CodeProblemsSolutions

        source/main.cpp
        source/CodeWars/Declarations.h

        source/CodeWars/2ndKyu/Declarations.h
        source/CodeWars/2ndKyu/PointerMonster.cpp

        source/CodeWars/3rdKyu/Declarations.h
        source/CodeWars/3rdKyu/BoolFuck.cpp

        source/CodeWars/4thKyu/Declarations.h
        source/CodeWars/4thKyu/SumByFactors.cpp
        source/CodeWars/4thKyu/HammingNumbers.cpp
        source/CodeWars/4thKyu/MysteryFunction.cpp
        source/CodeWars/4thKyu/FormatDuration.cpp
        source/CodeWars/4thKyu/Snail.cpp
        source/CodeWars/4thKyu/SumStrings.cpp

        source/CodeWars/5thKyu/Declarations.h
        source/CodeWars/5thKyu/Brainfuck.cpp
        source/CodeWars/5thKyu/MoveZeroes.cpp
        source/CodeWars/5thKyu/IncrementString.cpp

        source/CodeWars/6thKyu/Declarations.h
        source/CodeWars/6thKyu/SchrodingersBoolean.cpp
        source/CodeWars/6thKyu/TwoSum.cpp
        source/CodeWars/6thKyu/MissingInArithmeticProgression.cpp
        source/CodeWars/6thKyu/BitLetter.cpp
        source/CodeWars/6thKyu/FruitMachine.cpp
        source/CodeWars/6thKyu/CreatePhoneNumber.cpp
        source/CodeWars/6thKyu/IpToInt32.cpp
        source/CodeWars/6thKyu/LucasNumber.cpp
        source/CodeWars/6thKyu/DeleteDigit.cpp
        source/CodeWars/6thKyu/AmountOfPages.cpp
        source/CodeWars/6thKyu/MobiusFunction.cpp
        source/CodeWars/6thKyu/EmptyString.cpp


        source/LeetCode/Declarations.h

        source/LeetCode/Easy/Declarations.h
        source/LeetCode/Easy/PalindromeNumber.cpp
        source/LeetCode/Easy/TwoSum.cpp
        source/LeetCode/Easy/LongestCommonPrefix.cpp
        source/LeetCode/Easy/PlusOne.cpp
        source/LeetCode/Easy/RemoveElement.cpp
        source/LeetCode/Easy/AddBinary.cpp
        source/LeetCode/Easy/RomanToInteger.cpp
        source/LeetCode/Easy/SingleNumber.cpp
        source/LeetCode/Easy/ReverseBits.cpp
        source/LeetCode/Easy/HammingWeight.cpp

        source/LeetCode/Normal/Declarations.h
        source/LeetCode/Normal/AddTwoNumbers.cpp
        source/LeetCode/Normal/IntegerToRoman.cpp
        source/LeetCode/Normal/ReverseInteger.cpp
        source/LeetCode/Normal/DivideTwoIntegers.cpp
        source/LeetCode/Normal/LetterCombinations.cpp source/LeetCode/Normal/MyAtoi.cpp)
