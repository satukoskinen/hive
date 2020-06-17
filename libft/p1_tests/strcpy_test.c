#include <string.h>
#include <stdlib.h>
#include "../libft.h"

int		strcpy_test(void)
{
	int tests_passed = 0;
	
	char *dst1 = malloc(sizeof(char) * 7);
	char *dst2 = malloc(sizeof(char) * 7);
	char *src1 = "xxxxxx";

	char *ret1 = ft_strcpy(dst1, src1);
	char *ret2 = strcpy(dst2, src1);

	if (strcmp(ret1, ret2) == 0)
	{
		ft_putstr("ok");
		tests_passed++;
	}
	if (strcmp(dst1, dst2) == 0)
	{
		ft_putstr("ok");
		tests_passed++;
	}

	free(dst1);
	free(dst2);
	if (tests_passed == 2)
		return (1);
	return (0);
}
