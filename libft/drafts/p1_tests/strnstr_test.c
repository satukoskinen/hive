#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int    strnstr_test(void)
{
    int tests_passed = 0;

    char *str = "find the needlneedle needle in the haystack";

    char *p1 = ft_strnstr(str, "needle", 20);
    char *p2 = strnstr(str, "needle", 20);
    
    if (strcmp(p1, p2) == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR: strcmp(p1, p2) != 0");
        ft_putstr(p1);
        ft_putstr(p2);
    }
    
    p1 = ft_strnstr(str, "needle", 19);
    p2 = strnstr(str, "needle", 19);
    if (p1 == p2)
        tests_passed++;
    else
        ft_putstr("ERROR: p1 != p2 (null)");

    p1 = ft_strnstr(str, "", 20);
    p2 = strnstr(str, "", 20);
    if (strcmp(p1, p2) == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR: strcmp(p1, p2) != 0 (empty string)");
        ft_putstr(p1);
        ft_putstr(p2);
    }

    str = "need the /0 needle!";
    p1 = ft_strnstr(str, "needle", 19);
    p2 = strnstr(str, "needle", 19);
    if (p1 == p2)
        tests_passed++;
    else
        ft_putstr("ERROR: p1 != p2 (after null)");

    if (tests_passed == 4)
        return (1);
    return (0);
}