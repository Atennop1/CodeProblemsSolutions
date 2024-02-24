namespace SixthKyu
{
    long long int LucasNumber(int n)
    {
        if (n == 0)
            return 2;

        if (n == 1)
            return 1;

        if (n < 0)
            return LucasNumber(n + 2) - LucasNumber(n + 1);

        return LucasNumber(n - 2) + LucasNumber(n - 1);
    }
}