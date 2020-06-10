#include "../libft.h"
#include <string.h>

int main(void)
{
    char *str1 = ft_memalloc(10);
    char *str2 = ft_memalloc(10);
    strcpy(str1, "hello");
    strcpy(str2, "hello");
    ft_memset(str1, '@', 2);
    memset(str2, '@', 2);
    ft_putendl(str1);
    ft_putendl(str2);

    int i1[] = {13, 7, 8, 2, 0};
    int i2[] = {13, 7, 8, 2, 0};
    ft_memset(i1, 0, sizeof(int)*5);
    memset(i2, 0, sizeof(int)*5);
    for (int i = 0; i < 5; i++)
        ft_putnbr(i1[i]);
    ft_putchar('\n');
    for (int i = 0; i < 5; i++)
        ft_putnbr(i2[i]);
}