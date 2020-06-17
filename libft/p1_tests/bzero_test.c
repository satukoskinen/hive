#include "../libft.h"
#include <string.h>
#include <stdlib.h>

void	bzero_test(void)
{
	char *str1 = ft_memalloc(10);
    char *str2 = ft_memalloc(10);
    strcpy(str1, "hello");
    strcpy(str2, "hello");
    ft_bzero(str1, 2);
    bzero(str2, 2);
    for (int i = 0; i < 5; i++)
        ft_putchar(str1[i]);
    ft_putchar('\n');
    for (int i = 0; i < 5; i++)
        ft_putchar(str2[i]);
	ft_putchar('\n');
	free(str1);
	free(str2);

    int i1[] = {13, 7, 8, 2, 5};
    int i2[] = {13, 7, 8, 2, 5};
    ft_bzero(i1, sizeof(int)*5);
    bzero(i2, sizeof(int)*5);
    for (int i = 0; i < 5; i++)
        ft_putnbr(i1[i]);
    ft_putchar('\n');
    for (int i = 0; i < 5; i++)
        ft_putnbr(i2[i]);
	ft_putchar('\n');
}