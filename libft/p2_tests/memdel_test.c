#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

int		memdel_test(void)
{
	int tests_passed = 0;

	char *ptr1 = malloc(sizeof(char) * 100);
	int	*ptr2 = malloc(sizeof(int) * 25);
	void *ptr3 = malloc(100);

	ft_memdel((void**)&ptr1);
	ft_memdel((void**)&ptr2);
	ft_memdel(&ptr3);

	if (ptr1 == NULL && ptr2 == NULL && ptr3 == NULL)
		tests_passed++;
	else
		ft_putstr("\nERROR: ptr1 != NULL or ptr2 != NULL or ptr3 != NULL");

	if (tests_passed == 1)
	{
		printf(" OK\n");
		return (1);
	}
	return (0);
}