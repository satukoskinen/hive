#include <stdlib.h>
#include "../libft.h"

int atoi_test(void)
{
    int tests_passed = 0;

    if (ft_atoi("40002") == atoi("40002"))
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_atoi("  0050") == atoi("  0050"))
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_atoi("42school") == atoi("42school"))
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_atoi("school42") == atoi("school42"))
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_atoi("\t\n\v\f\r 42") == atoi("\t\n\v\f\r 42"))
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_atoi("2147483647 1") == atoi("2147483647 1"))
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_atoi("-2147483648") == atoi("-2147483648"))
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_atoi("+-2") == atoi("+-2"))
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_atoi("-+2") == atoi("-+2"))
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (ft_atoi("") == atoi(""))
        tests_passed++;
    else
    {
        ft_putstr("ERROR\n");
    }
    if (tests_passed == 10)
        return (1);
    return (0);
}