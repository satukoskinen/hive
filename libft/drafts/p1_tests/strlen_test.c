#include "../libft.h"
#include <string.h>

int		strlen_test(void)
{
	int tests_passed = 0;
	char *s1 = "test";
	char *s2 = "test \0 test";

	if (ft_strlen(s1) == strlen(s1))
	{
		ft_putendl("OK");
		tests_passed++;
	}
	if (ft_strlen(s1) != strlen(s2))
	{
		ft_putendl("OK");
		tests_passed++;
	}	if (ft_strlen(s2) == strlen(s2))
	{
		ft_putendl("OK");
		tests_passed++;
	}
	if (tests_passed == 3)
		return (1);
	else
		return (0);
}