#include "../libft.h"
#include <string.h>

int	memccpy_test(void)
{
	int tests_passed = 0;
	char c_src[10] = "example";
	char c_dest1[10] = "1234567";
	char c_dest2[10] = "1234567";

	if (ft_memccpy(c_dest1, c_src, 'x', 8) == NULL)
		ft_putendl("ok");
	else
		ft_putendl(ft_memccpy(c_dest1, c_src, 'x', 8));
	ft_putendl(c_dest1);
	if (memccpy(c_dest2, c_src, 'x', 8) == NULL)
		ft_putendl("ok");
	else
		ft_putendl(memccpy(c_dest2, c_src, 'x', 8));
	ft_putendl(c_dest2);

	if (ft_memccpy(c_dest1, c_src, 'z', 8) == NULL)
		ft_putendl("ok");
	else
		ft_putendl(ft_memccpy(c_dest1, c_src, 'x', 8));
	ft_putendl(c_dest1);
	if (memccpy(c_dest2, c_src, 'z', 8) == NULL)
		ft_putendl("ok");
	else
		ft_putendl(memccpy(c_dest2, c_src, 'x', 8));
	ft_putendl(c_dest2);

	int i_src[10] = {1, 2, 3, 4, 5, 6, 7};
	int i_dest1[10] = {9, 9, 9, 9, 9, 9, 9};
	int i_dest2[10] = {9, 9, 9, 9, 9, 9, 9};
	if (ft_memccpy(i_dest1, i_src, 0, sizeof(int)*7) == NULL)
		ft_putendl("ok");
	for (int i = 0; i < 7; i++)
	{
		ft_putnbr(i_dest1[i]);
		ft_putchar('\n');
	}
	if (memccpy(i_dest2, i_src, 0, sizeof(int)*7) == NULL)
		ft_putendl("ok");
	for (int i = 0; i < 7; i++)
	{
		ft_putnbr(i_dest2[i]);
		ft_putchar('\n');
	}

	if (ft_memccpy(i_dest1, i_src, 'x', sizeof(int)*7) == NULL)
		ft_putendl("ok");
	for (int i = 0; i < 7; i++)
	{
		ft_putnbr(i_dest1[i]);
		ft_putchar('\n');
	}
	if (memccpy(i_dest2, i_src, 'x', sizeof(int)*7) == NULL)
		ft_putendl("ok");
	for (int i = 0; i < 7; i++)
	{
		ft_putnbr(i_dest2[i]);
		ft_putchar('\n');
	}

	if (tests_passed == 0)
		return (1);
	return (0);
}