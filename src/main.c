#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>
#include <check.h>

#include "tests.h"

/*
 * main serves as a driver that pushes Check test cases
 */

int main( int argc, char* argv[])
{
	// create the test suite and test case
	Suite* suite = suite_create("test suite #1");
	TCase* test_case = tcase_create("test case #1");

	// add our test(s) to the test case and the test case
	// to the suite
	tcase_add_test(test_case, test_convert_roman_one_to_arrabic);
	tcase_add_test(test_case, test_convert_roman_two_to_arrabic);
	suite_add_tcase(suite, test_case);

	// set up an SRunner to track the state of our tests
	SRunner* state_runner = srunner_create(suite);
	
	// run all tests
	srunner_run_all(state_runner, CK_VERBOSE);
	uint32_t tests_failed = srunner_ntests_failed(state_runner);

	return tests_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
