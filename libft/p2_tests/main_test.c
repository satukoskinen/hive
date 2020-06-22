#include "tests.h"
#include <stdio.h>

int main(void)
{
	int tests_passed = 0;
	int tests_run = 0;

	printf("ft_memalloc: ");
	tests_passed += memalloc_test();
	tests_run++;
	printf("ft_memdel: ");
	tests_passed += memdel_test();
	tests_run++;
	printf("ft_strnew: ");
	tests_passed += strnew_test();
	tests_run++;
	printf("ft_strdel: ");
	tests_passed += strdel_test();
	tests_run++;

	printf("\nPART 2: tests passed: %d out of %d\n", tests_passed, tests_run);
	printf("\tmodify main_test.c to check for memory leaks\n");
//	while (1)
//		;
	return (0);
}