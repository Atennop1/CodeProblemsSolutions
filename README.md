# CodeProblemsSolutions
This is a repository that stores my solutions to problems from CodeWars and LeetCode, which I do in C++ to study algorithms and the language itself.

## Project structure
Problems are divided into their own folders according to difficulty, for CodeWars these are kyu, and for LeetCode the Easy, Normal and Hard difficulties. Each difficulty's problems are in their own namespace to avoid conflicts and each folder has its own `Declarations.h` file, through which you can connect problems to the file. Also there are also files `LeetCode/Declaration.h` and `CodeWars/Declarations.h`, through which you can connect all problems at once.

It’s also worth saying that in the case of LeetCode, all problems are in the Solutions class and marked static, so they can be safely called. Thus, calling the 2kyu task "PointerMonster" and the Normal LeetCode problem "IntToRoman" will look like this:

```cpp
#include "CodeWars/Declarations.h"
#include "LeetCode/Declarations.h"

int main()
{
    SecondKyu::PointerMonster();
    LeetCodeNormal::Solutions::IntToRoman(5);
    return 0;
}
```
