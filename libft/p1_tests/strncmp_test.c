#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int strncmp_test(void)
{
    int tests_passed = 0;

    if (ft_strncmp("hello world \t", "hello world \t", 20) == 0 && strncmp("hello world \t", "hello world \t", 20) == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_strncmp("\200", "\0", 1) > 0 && strncmp("\200", "\0", 1) > 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
        ft_putnbr(ft_strncmp("\200", "\0", 1));
        ft_putstr("\n");
        ft_putnbr(strncmp("\200", "\0", 1));
    }
    if (ft_strncmp("\200", "\0", 0) == 0 && strncmp("\200", "\0", 0) == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
        ft_putnbr(ft_strncmp("\200", "\0", 0));
        ft_putstr("\n");
        ft_putnbr(strncmp("\200", "\0", 0));
    }
    if (ft_strncmp("", "\0", 1) == 0 && strncmp("", "\0", 1) == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_strncmp("test\0 test", "test", 10) == 0 && strncmp("test\0 test", "test", 10) == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_strncmp("abcd", "abcde", 4) == 0 && strncmp("abcd", "abcde", 4) == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }

    if (tests_passed == 6)
        return (1);
    return (0);
} 