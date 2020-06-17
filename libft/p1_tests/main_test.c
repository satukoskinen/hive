#include "tests.h"
#include <stdio.h>

int main(void)
{
	int tests_passed = 0;
	int tests_run = 0;

	tests_passed += memset_test();
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
	tests_passed += strncpy_test();
	tests_run++;
	tests_passed += strcat_test();
	tests_run++;
	tests_passed += strncat_test();
	tests_run++;
	tests_passed += strlcat_test();
	tests_run++;
	tests_passed += strchr_test();
	tests_run++;
	tests_passed += strrchr_test();
	tests_run++;
	tests_passed += strstr_test();
	tests_run++;
	tests_passed += strnstr_test();
	tests_run++;
	tests_passed += strcmp_test();
	tests_run++;
	tests_passed += strncmp_test();
	tests_run++;
	tests_passed += atoi_test();
	tests_run++;
	tests_passed += isalpha_test();
	tests_run++;
	tests_passed += isdigit_test();
	tests_run++;
	tests_passed += isalnum_test();
	tests_run++;
	tests_passed += isascii_test();
	tests_run++;
	tests_passed += isprint_test();
	tests_run++;

	printf("\nPart 1: tests passed: %d out of %d\n", tests_passed, tests_run);
	while (1)
		;
	return (0);
}