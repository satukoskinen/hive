#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int     strchr_test(void)
{
    int tests_passed = 0;

    char *str = "find the correct @ character @";

    char *p1 = ft_strchr(str, '@');
    char *p2 = strchr(str, '@');
    
    if (strcmp(p1, p2) == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR: strcmp(p1, p2) != 0");
        ft_putstr(p1);
        ft_putstr(p2);
    }
    
    p1 = ft_strchr(str, 'x');
    p2 = strchr(str, 'x');
    if (p1 == p2)
        tests_passed++;
    else
    {
        ft_putstr("ERROR: p1 != p2");
        ft_putstr(p1);
        ft_putstr(p2);
    }

    p1 = ft_strchr(str, '\0');
    p2 = strchr(str, '\0');
    if (strcmp(p1, p2) == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR: strcmp(p1, p2) != 0");
        ft_putstr(p1);
        ft_putstr(p2);
    }
    
    if (tests_passed == 3)
        return (1);
    return (0);
}
