#include "../libft.h"
#include <string.h>

void	memcmp_test(void)
{
	char *s1 = "testing this string\0 which continues";
	char *s2 = "testing this string\0 which continues";
	char *s3 = "testing this string ";

	ft_putnbr(ft_memcmp(s1, s2, strlen(s1) + 1));
	ft_putnbr(memcmp(s1, s2, strlen(s1 + 1)));

	ft_putnbr(ft_memcmp(s1, s3, strlen(s3)));
	ft_putnbr(memcmp(s1, s3, strlen(s3)));

	ft_putnbr(ft_memcmp(s1, s3, strlen(s3) - 1));
	ft_putnbr(memcmp(s1, s3, strlen(s3) - 1));
}