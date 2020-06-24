#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

int isascii_test(void)
{
    int tests_passed = 0;
    int c = 0;

    while (c <= 127)
    {
        if (ft_isascii(c) > 0 && isascii(c) > 0)
            tests_passed++;
        else
			printf("\nERROR: %c", c);
        c++;
    }
    if (ft_isascii(128) == 0 && isascii(128) == 0)
        tests_passed++;
    else
			printf("\nERROR: 128");
    if (ft_isascii(-1) == 0 && isascii(-1) == 0)
        tests_passed++;
    else
			printf("\nERROR: -1");

    if (tests_passed == 130)
        return (1);
    return (0);
}