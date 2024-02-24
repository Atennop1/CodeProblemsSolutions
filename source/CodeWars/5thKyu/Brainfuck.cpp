#include <string>
#include <stack>

namespace FifthKyu
{
    std::string Brainfuck(const std::string &code, const std::string &input)
    {
        std::string result;
        unsigned char memory[30000] { };
        unsigned char *memory_pointer = memory;

        std::stack<const char*> instructions_stack = { };
        const char *instruction_pointer = &code[0];
        const char *input_pointer = &input[0];

        while (&code.back() - instruction_pointer != -1 && &input.back() - input_pointer != -2)
        {
            switch (*instruction_pointer)
            {
                case '>':
                    memory_pointer++;
                    break;

                case '<':
                    memory_pointer--;
                    break;

                case '+':
                    (*memory_pointer)++;
                    break;

                case '-':
                    (*memory_pointer)--;
                    break;

                case '.':
                    result += (char)(*memory_pointer);
                    break;

                case ',':
                    *memory_pointer = *input_pointer;
                    input_pointer++;
                    break;

                case '[':
                {
                    if (*memory_pointer != 0)
                    {
                        instructions_stack.push(instruction_pointer + 1);
                        break;
                    }

                    unsigned int nesting = 0;
                    while (*(++instruction_pointer) != ']' || nesting != 0)
                    {
                        if (*instruction_pointer == '[')
                            nesting++;

                        if (*instruction_pointer == ']')
                            nesting--;
                    }

                    break;
                }

                case ']':
                    if ((*memory_pointer) == 0)
                    {
                        instructions_stack.pop();
                        break;
                    }

                    instruction_pointer = instructions_stack.top();
                    continue;

                default:
                    break;
            }

            instruction_pointer++;
        }

        return result;
    }
}