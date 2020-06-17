#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int    strstr_test(void)
{
    int tests_passed = 0;

    char *str = "find the needlneedle needle in the haystack";

    char *p1 = ft_strstr(str, "needle");
    char *p2 = strstr(str, "needle");
    
    if (strcmp(p1, p2) == 0)
        tests_passed++;
    else
    {
        ft_putstr("ERROR: strcmp(p1, p2) != 0");
        ft_putstr(p1);
        ft_putstr(p2);
    }
    
    p1 = ft_strstr(str, "needle  ");
    p2 = strstr(str, "needle  ");
    if (p1 == p2)
        tests_passed++;
    else
        ft_putstr("ERROR: p1 != p2 (null)");

    p1 = ft_strstr(str, "");
    p2 = strstr(str, "");
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
