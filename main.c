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
        case '*':
            assert(0 && "TODO: not implemented *");
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

int main(void)
{
    check_glob("main.?", "main.c");
    return 0;
}