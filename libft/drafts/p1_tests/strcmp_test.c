#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int strcmp_test(void)
{
    int tests_passed = 0;

    if (ft_strcmp("hello world \t", "hello world \t") == 0 && strcmp("hello world \t", "hello world \t") == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_strcmp("\200", "\0") > 0 && strcmp("\200", "\0") > 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
        ft_putnbr(ft_strcmp("\200", "\0"));
        ft_putstr("\n");
        ft_putnbr(strcmp("\200", "\0"));
    }
    if (ft_strcmp("", "\0") == 0 && strcmp("", "\0") == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_strcmp("test\0 test", "test") == 0 && strcmp("test\0 test", "test") == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_strcmp("abcd", "abcde") < 0 && strcmp("abcd", "abcde") < 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }

    if (tests_passed == 5)
        return (1);
    return (0);
} 