#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int     strcat_test(void)
{
    int tests_passed = 0;

    char *s1 = malloc(sizeof(char) * 25);
    char *s2 = malloc(sizeof(char) * 25);
    char *src = " and this last";

    s1[0] = '\0';
    s2[0] = '\0';

    char *ret1 = ft_strcat(s1, "this first");
    char *ret2 = strcat(s2, "this first");

    if (strcmp(ret1, ret2) == 0)
        tests_passed++;
    else
    {
        ft_putendl("ERROR: strcmp(ret1, ret2) != 0");
        ft_putendl(ret1);
        ft_putendl(ret2);
    }
    if (strcmp(s1, s2) == 0)
        tests_passed++;
    else
    {
        ft_putendl("ERROR: strcmp(s1, s2) != 0");
        ft_putendl(s1);
        ft_putendl(s2);
    }

    ret1 = ft_strcat(s1, src);
    ret2 = ft_strcat(s2, src);

    if (strcmp(ret1, ret2) == 0)
        tests_passed++;
    else
    {
        ft_putendl("ERROR: strcmp(ret1, ret2) != 0");
        ft_putendl(ret1);
        ft_putendl(ret2);
    }
    if (strcmp(s1, s2) == 0)
        tests_passed++;
    else
    {
        ft_putendl("ERROR: strcmp(s1, s2) != 0");
        ft_putendl(s1);
        ft_putendl(s2);
    }
    
    free(s1);
    free(s2);
    if (tests_passed == 4)
        return (1);
    return (0);
}