#include "tests.h"
#include <stdio.h>

int main(void)
{
	int tests_passed = 0;
	int tests_run = 0;

    tests_passed += memalloc_test();
    tests_run++;

	printf("\nPart 2: tests passed: %d out of %d\n", tests_passed, tests_run);
//	while (1)
//		;
	return (0);
}