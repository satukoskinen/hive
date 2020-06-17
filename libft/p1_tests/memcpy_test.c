#include "../libft.h"
#include <string.h>

void	memcpy_test(void)
{
	char c_src[10] = "example";
	char c_dest1[10];
	char c_dest2[10];

	ft_putendl(ft_memcpy(c_dest1, c_src, 8));
	ft_putendl(c_dest1);
	ft_putendl(ft_memcpy(c_dest2, c_src, 8));
	ft_putendl(c_dest2);

	int i_src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i_dest1[10];
	int i_dest2[10];

	ft_putnbr(*(int*)ft_memcpy(i_dest1, i_src, sizeof(int)*10));
	ft_putchar('\n');
	for (int i = 0; i < 10; i++)
		ft_putnbr(i_dest1[i]);
	ft_putchar('\n');
	ft_putnbr(*(int*)memcpy(i_dest2, i_src, sizeof(int)*10));
	ft_putchar('\n');
	for (int i = 0; i < 10; i++)
		ft_putnbr(i_dest2[i]);
	ft_putchar('\n');
}