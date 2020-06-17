#include <ctype.h>
#include "../libft.h"

int isdigit_test(void)
{
    int tests_passed = 0;
    char c = 0;

    while (c <= 126)
    {
        if (c < '0' && ft_isdigit(c) == 0 && isdigit(c) == 0)
            tests_passed++;
        else if (c <= '9' && ft_isdigit(c) > 0 && isdigit(c) > 0)
            tests_passed++;
        else if (c > '9' && ft_isdigit(c) == 0 && isdigit(c) == 0)
            tests_passed++;
        else
        {
            ft_putstr("ERROR\n");
            ft_putchar(c);
        }
        c++;
    }
    if (ft_isdigit(127) == 0 && isdigit(127) == 0)
        tests_passed++;
    else
        ft_putstr("ERROR\n");
    if (ft_isdigit(128) == 0 && isdigit(128) == 0)
        tests_passed++;
    else
        ft_putstr("ERROR 1");
    if (ft_isdigit(-1) == 0 && isdigit(-1) == 0)
        tests_passed++;
    else
        ft_putstr("ERROR 2");

    if (tests_passed == 128)
        return (1);
    return (0);
}