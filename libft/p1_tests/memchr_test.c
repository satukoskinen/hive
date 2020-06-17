#include "../libft.h"
#include <string.h>

void	memchr_test(void)
{
	char *s = "Hi there";

	char *ret1 = ft_memchr(s, 'e', 9);
	char *ret2 = memchr(s, 'e', 9);
	ft_putendl(ret1);
	ft_putendl(ret2);

	char *ret3 = ft_memchr(s, 'x', 9);
	char *ret4 = memchr(s, 'x', 9);
	if (ret3 == NULL)
		ft_putendl("null");
	if (ret4 == NULL)
		ft_putendl("null");

	char *ret5 = ft_memchr(s, 'x', 3);
	char *ret6 = memchr(s, 'x', 3);
	if (ret5 == NULL)
		ft_putendl("null");
	if (ret6 == NULL)
		ft_putendl("null");
}