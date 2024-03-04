namespace SixthKyu
{
    int BreakTheWeb(int strength, int width)
    {
        if (strength <= 0 || width <= 0)
            return 0;

        int result = 0;
        int current_position = 1;

        while (strength - current_position * 1000 >= 0)
        {
            for (int i = 0; i < width - current_position + 1; i++)
            {
                if ((strength -= current_position * 1000) < 0)
                    break;

                result++;
            }

            current_position++;
        }

        return result;
    }
}