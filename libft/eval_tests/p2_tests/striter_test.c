#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

static void    ft_iter(char *s)
{
    *s += 1;
}

int     striter_test(void)
{
    int tests_passed = 0;

    char *str1 = malloc(sizeof(char) * 10);
    char *str2 = malloc(sizeof(char) * 10);
    str1 = strcpy(str1, "abcdefghi");
    str2 = strcpy(str2, "bcdefghij");

    void (*f)(char*) = ft_iter;

    ft_striter(str1, f);

    if (strcmp(str1, str2) == 0)
        tests_passed++;
    else
        printf("\nERROR: strcmp(str1, str2) != 0\n%s\n%s", str1, str2);

    free(str1);
    free(str2);
    if (tests_passed == 1)
    {
        printf("\tOK\n");
        return (1);
    }

    return (0);
}