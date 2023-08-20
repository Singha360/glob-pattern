#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool glob(const char *pattern, const char *text)
{
    while (*pattern != '\0' && *text != '\0')
    {
        switch (*pattern)
        {
        case '?': {
            ++pattern;
            ++text;
        }
        break;
        case '*': {
            if (glob(pattern + 1, text))
            {
                return true;
            }
            else
            {

                ++text;
            }
        }
        break;
        case '[':
            assert(0 && "TODO: not implemented [");
            break;
        default: {
            if (*pattern == *text)
            {
                ++pattern;
                ++text;
            }
            else
            {
                return false;
            }
        }
        break;
        }
    }
    return (*pattern == '\0' && *text == '\0');
}

void check_glob(const char *pattern, const char *text)
{
    bool actual = glob(pattern, text);
    printf("%s <=> %s => %s\n", pattern, text, actual ? "true" : "false");
}

void new_line()
{
    printf("\n");
}

int main(void)
{
    check_glob("main.?", "main.c");     // true
    check_glob("main.?", "main.h");     // true
    check_glob("main.?", "main.cpp");   // false
    check_glob("main.???", "main.cpp"); // true
    check_glob("main.?", "main");       // false
    new_line();
    check_glob("*.cpp", "main.cpp"); // true
    check_glob("*.cpp", "main.c");   // false
    check_glob("main.*", "main.c");  // true
    return 0;
}