#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int		strncpy_test(void)
{
	int tests_passed = 0;

	char *dst1 = malloc(sizeof(char) * 7);
	char *dst2 = malloc(sizeof(char) * 7);
	char *src1 = "xxxxxx";

	char *ret1 = ft_strncpy(dst1, src1, 6);
	char *ret2 = strncpy(dst2, src1, 6);

	if (memcmp(ret1, ret2, 7) == 0)
	{
		ft_putstr("1 ok");
		tests_passed++;
	}
	if (memcmp(dst1, dst2, 7) == 0)
	{
		ft_putstr("2 ok");
		tests_passed++;
	}
	free(dst1);
	free(dst2);

	dst1 = malloc(sizeof(char) * 10);
	dst2 = malloc(sizeof(char) * 10);
	ret1 = ft_strncpy(dst1, src1, 10);
	ret2 = strncpy(dst2, src1, 10);
	if (memcmp(ret1, ret2, 10) == 0)
	{
		ft_putstr("3 ok");
		tests_passed++;
	}
	if (memcmp(dst1, dst2, 10) == 0)
	{
		ft_putstr("4 ok");
		tests_passed++;
	}
	free(dst1);
	free(dst2);	

	dst1 = malloc(sizeof(char) * 10);
	dst2 = malloc(sizeof(char) * 10);
	ret1 = ft_strncpy(dst1, src1, 15);
	ret2 = strncpy(dst2, src1, 15);
	if (memcmp(ret1, ret2, 10) == 0)
	{
		ft_putstr("5 ok");
		tests_passed++;
	}
	if (memcmp(dst1, dst2, 10) == 0)
	{
		ft_putstr("6 ok");
		tests_passed++;
	}
	free(dst1);
	free(dst2);	
	if (tests_passed == 6)
		return (1);
	return (0);
}