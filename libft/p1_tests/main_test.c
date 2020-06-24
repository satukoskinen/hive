#include "tests.h"
#include <stdio.h>

int main(void)
{
	int tests_passed = 0;
	int tests_run = 0;

	printf("ft_memset:");
	tests_passed += memset_test();
	tests_run++;
	printf("ft_bzero:");
	tests_passed += bzero_test();
	tests_run++;
	printf("ft_memcpy:");
	tests_passed += memcpy_test();
	tests_run++;
	printf("ft_memccpy:");
	tests_passed += memccpy_test();
	tests_run++;
	printf("ft_memmove:");
	tests_passed += memmove_test();
	tests_run++;
	printf("ft_memchr:");
	tests_passed += memchr_test();
	tests_run++;
	printf("ft_memcmp:");
	tests_passed += memcmp_test();
	tests_run++;
	printf("ft_strlen:");
	tests_passed += strlen_test();
	tests_run++;
	printf("ft_strdup:");
	tests_passed += strdup_test();
	tests_run++;
	printf("ft_strcpy:");
	tests_passed += strcpy_test();
	tests_run++;
	printf("ft_strncpy:");
	tests_passed += strncpy_test();
	tests_run++;
	printf("ft_strcat:");
	tests_passed += strcat_test();
	tests_run++;
	printf("ft_strncat:");
	tests_passed += strncat_test();
	tests_run++;
	printf("ft_strlcat:");
	tests_passed += strlcat_test();
	tests_run++;
	printf("ft_strchr:");
	tests_passed += strchr_test();
	tests_run++;
	printf("ft_strrchr:");
	tests_passed += strrchr_test();
	tests_run++;
	printf("ft_strstr:");
	tests_passed += strstr_test();
	tests_run++;
	printf("ft_strnstr:");
	tests_passed += strnstr_test();
	tests_run++;
	printf("ft_strcmp:");
	tests_passed += strcmp_test();
	tests_run++;
	printf("ft_strncmp:");
	tests_passed += strncmp_test();
	tests_run++;
	printf("ft_atoi:");
	tests_passed += atoi_test();
	tests_run++;
	printf("ft_isalpha:");
	tests_passed += isalpha_test();
	tests_run++;
	printf("ft_isdigit:");
	tests_passed += isdigit_test();
	tests_run++;
	printf("ft_isalnum:");
	tests_passed += isalnum_test();
	tests_run++;
	printf("ft_isascii:");
	tests_passed += isascii_test();
	tests_run++;
	printf("ft_isprint:");
	tests_passed += isprint_test();
	tests_run++;

/*	printf("\nPART 1: tests passed: %d out of %d\n", tests_passed, tests_run);
**	while (1)
**		;
*/	return (0);
}