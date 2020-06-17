#include <ctype.h>
#include "../libft.h"

int isprint_test(void)
{
    int tests_passed = 0;
    char c = 0;

    while (c <= 126)
    {
        if (c < 32 && ft_isprint(c) == 0 && isprint(c) == 0)
            tests_passed++;
        else if (c <= 126 && ft_isprint(c) > 0 && isprint(c) > 0)
            tests_passed++;
        else
        {
            ft_putstr("ERROR\n");
            ft_putchar(c);
        }
        c++;
    }
    if (ft_isprint(127) == 0 && isprint(127) == 0)
        tests_passed++;
    else
        ft_putstr("ERROR\n");
    if (ft_isprint(128) == 0 && isprint(128) == 0)
        tests_passed++;
    else
        ft_putstr("ERROR 1");
    if (ft_isprint(-1) == 0 && isprint(-1) == 0)
        tests_passed++;
    else
        ft_putstr("ERROR 2");

    if (tests_passed == 130)
        return (1);
    return (0);
}