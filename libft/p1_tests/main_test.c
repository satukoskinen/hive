#include "tests.h"
#include <stdio.h>

int main(void)
{
	int tests_passed = 0;
	int tests_run = 0;

/*	tests_passed += memset_test();
	tests_run++;
	tests_passed += bzero_test();
	tests_run++;
	tests_passed += memcpy_test();
	tests_run++;
	tests_passed += memccpy_test();
	tests_run++;
	tests_passed += memmove_test();
	tests_run++;
	tests_passed += memchr_test();
	tests_run++;
	tests_passed += memcmp_test();
	tests_run++;
	tests_passed += strlen_test();
	tests_run++;
	tests_passed += strdup_test();
	tests_run++;
	tests_passed += strcpy_test();
	tests_run++;
*/	tests_passed+= strncpy_test();
	tests_run++;

	printf("\ntests passed: %d out of %d\n", tests_passed, tests_run);
//	while (1)
//		;
	return (0);
}