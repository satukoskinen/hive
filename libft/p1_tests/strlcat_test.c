#include "../libft.h"
#include <stdlib.h>
#include <string.h>

int strlcat_test(void)
{
    int tests_passed = 0;

    char *s1 = malloc(sizeof(char) * 20);
    char *s2 = malloc(sizeof(char) * 20);
    char *src = " and this last";

    s1[0] = '\0';
    s2[0] = '\0';

    size_t ret2 = strlcat(s2, "this first", 20);

    if (ft_strlcat(s1, "this first", 20) == ret2)
        tests_passed++;
    else
    {
        ft_putstr("ERROR: ret1 != ret2\n");
        ft_putnbr(ft_strlcat(s1, "this first", 20));
        ft_putnbr(ret2);
        ft_putchar('\n');
    }
    if (strcmp(s1, s2) == 0)
        tests_passed++;
    else
    {
        ft_putendl("ERROR: strcmp(s1, s2) != 0");
        ft_putendl(s1);
        ft_putendl(s2);
    }

    ret2 = strlcat(s2, src, 20);
    if (ft_strlcat(s1, src, 20) == ret2)
        tests_passed++;
    else
    {
        ft_putstr("ERROR: ret1 != ret2\n");
        ft_putnbr(ft_strlcat(s1, src, 20));
        ft_putnbr(ret2);
        ft_putchar('\n');
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