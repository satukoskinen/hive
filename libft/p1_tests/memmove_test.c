#include "../libft.h"
#include <string.h>

int	memmove_test(void)
{
	int tests_passed = 0;
	char c_dest1[10] = "example";
	char c_dest2[10] = "example";
	char *c_src1 = &c_dest1[2];
	char *c_src2 = &c_dest2[2];

	ft_putendl(ft_memmove(c_dest1, c_src1, 4));
	ft_putendl(c_dest1);
	ft_putendl(memmove(c_dest2, c_src2, 4));
	ft_putendl(c_dest2);
	return (tests_passed);
}