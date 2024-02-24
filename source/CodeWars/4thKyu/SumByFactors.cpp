#include <vector>
#include <string>
#include "Declarations.h"

namespace FourthKyu
{
    std::vector<int> FindPrimeNumbers(const int n)
    {
        std::vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;

        for (int p = 2; p * p <= n; p++)
            if (is_prime[p])
                for (int i = p * p; i <= n; i += p)
                    is_prime[i] = false;

        std::vector<int> result { };
        for (int i = 2; i < is_prime.size(); i++)
            if (is_prime[i])
                result.push_back(i);

        return result;
    }

    std::string SumOfDivided::Return(const std::vector<int> &list)
    {
        if (list.empty())
            return "";

        std::string result;
        int absolute_max = list[0];

        for (int i : list)
            if (absolute_max < std::abs(i))
                absolute_max = std::abs(i);

        std::vector<int> primes = FindPrimeNumbers(absolute_max);

        for (int prime : primes)
        {
            int count = 0;
            long sum = 0;

            for (int j : list)
            {
                if (j % prime == 0)
                {
                    count++;
                    sum += j;
                }
            }

            if (count != 0)
                result += "(" + std::to_string(prime) + " " + std::to_string(sum) + ")";
        }

        return result;
    };
}