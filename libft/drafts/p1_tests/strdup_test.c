#include "string.h"
#include <stdlib.h>
#include "../libft.h"

int		strdup_test(void)
{
	int tests_passed = 0;

	char *s1 = ft_strdup("test testfoisfuaöocmapöoeixpaxiepqwir ceocrjoaisuaoweisucdaweixquoeuqoxeuoqndoeas");
	char *s2 = strdup("test testfoisfuaöocmapöoeixpaxiepqwir ceocrjoaisuaoweisucdaweixquoeuqoxeuoqndoeas");
	if (strcmp(s1, s2) == 0)
	{
		ft_putstr("ok");
		tests_passed++;
	}
	free(s1);
	free(s2);

	s1 = ft_strdup("");
	s2 = strdup("");
	if (strcmp(s1, s2) == 0)
	{
		ft_putstr("ok");
		tests_passed++;
	}
	free(s1);
	free(s2);
	if (tests_passed == 2)
		return (1);
	return (0);
}