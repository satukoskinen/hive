#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int	main(int argc, char **argv)
{
	while (argc > 1)
	{
		printf("atoi: %d\n", atoi(argv[argc - 1]));
		printf("ft_atoi: %d\n", ft_atoi(argv[argc - 1]));
		argc--;
	}
	return (0);
}