#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

int isalpha_test(void)
{
    int tests_passed = 0;
    char c = 0;

    while (c <= 126)
    {
        if (c < 'A' && ft_isalpha(c) == 0 && isalpha(c) == 0)
            tests_passed++;
        else if (c <= 'Z' && ft_isalpha(c) > 0 && isalpha(c) > 0)
            tests_passed++;
        else if (c < 'a' && ft_isalpha(c) == 0 && isalpha(c) == 0)
            tests_passed++;
        else if (c <= 'z' && ft_isalpha(c) > 0 && isalpha(c) > 0)
            tests_passed++;
        else if (c > 'z' && ft_isalpha(c) == 0 && isalpha(c) == 0)
            tests_passed++;
        else
			printf("\nERROR: %c", c);
        c++;
    }
    if (ft_isalpha(127) == 0 && isalpha(127) == 0)
        tests_passed++;
    else
        printf("\nERROR: 127");
    if (ft_isalpha(128) == 0 && isalpha(128) == 0)
        tests_passed++;
    else
        printf("\nERROR: 128");
    if (ft_isalpha(-1) == 0 && isalpha(-1) == 0)
        tests_passed++;
    else
        printf("\nERROR: -1");

    if (tests_passed == 128)
        return (1);
    return (0);
}