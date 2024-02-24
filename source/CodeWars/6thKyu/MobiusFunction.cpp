#include <valarray>

namespace SixthKyu
{
    int Mobius(long long int n)
    {
        int count_of_factors = 0;

        for (int i = 2; i <= sqrt(n); i = (i == 2 ? 3 : i + 2))
        {
            if (n % i == 0)
            {
                n /= i;
                count_of_factors++;

                if (n % i == 0)
                    return 0;
            }
        }

        return (count_of_factors % 2 == 0) ? -1 : 1;
    }
}