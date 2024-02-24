#include <stack>
#include <cstring>

namespace ThirdKyu
{
    char* BoolFuck(const char *code, const char *input_string)
    {
        bool memory[30000] { };
        bool result[10000] { };
        bool input[10000] { };

        int memory_index = 0;
        int result_index = 0;
        int input_index = 0;

        std::stack<const char*> cycles_starts_stack = { };
        const char *instruction_pointer = &code[0];
        unsigned int nesting_level;

        for (int i = 0; i < (int)strlen(input_string) * 8; i++)
            input[i] = (char)(input_string[i / 8] << (7 - (i % 8))) >> 7;

        while (*instruction_pointer != '\0')
        {
            switch (*instruction_pointer)
            {
                case '+':
                    memory[memory_index] = !memory[memory_index];
                    break;

                case ',':
                    memory[memory_index] = input_index != (int)strlen(input_string) * 8 && input[input_index++];
                    break;

                case ';':
                    result[result_index++] = memory[memory_index];
                    break;

                case '<':
                    memory_index--;
                    break;

                case '>':
                    memory_index++;
                    break;

                case '[':
                    if (memory[memory_index])
                    {
                        cycles_starts_stack.push(instruction_pointer);
                        break;
                    }

                    nesting_level = 0;
                    while (*(++instruction_pointer) != ']' || nesting_level != 0)
                        nesting_level += (*instruction_pointer == '[' ? 1 : (*instruction_pointer == ']' ? -1 : 0));

                    break;

                case ']':
                    if (!memory[memory_index])
                    {
                        cycles_starts_stack.pop();
                        break;
                    }

                    instruction_pointer = cycles_starts_stack.top();
                    break;
            }

            instruction_pointer++;
        }

        char *result_bytes = new char[1250] { };
        for (int i = 0; i < result_index; i++)
            result_bytes[i / 8] += (result[i] ? 1 : 0) << (i % 8);

        result_bytes[result_index] = '\0';
        return result_bytes;
    }
}