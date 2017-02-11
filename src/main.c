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
	// create the test suite
	Suite* suite = suite_create("test suite");
	
	// create the Roman to Arabic test case
	TCase* r_t_a_test_case = tcase_create("convert_roman_to_arabic test cases");

	// add our convert_roman_to_arabic test(s) to the test case
	tcase_add_test(r_t_a_test_case, test_convert_roman_one_to_arrabic);
	tcase_add_test(r_t_a_test_case, test_convert_roman_two_to_arrabic);
	tcase_add_test(r_t_a_test_case, test_convert_roman_three_to_arrabic);
	tcase_add_test(r_t_a_test_case, test_convert_roman_five_to_arrabic);
	tcase_add_test(r_t_a_test_case, test_convert_roman_ten_to_arrabic);
	tcase_add_test(r_t_a_test_case, test_convert_roman_fifty_to_arrabic);
	tcase_add_test(r_t_a_test_case, test_convert_roman_hundred_to_arrabic);
	tcase_add_test(r_t_a_test_case, test_convert_roman_fivehundred_to_arrabic);
	tcase_add_test(r_t_a_test_case, test_convert_roman_thousand_to_arrabic);	
	
	// create the validate test case
	TCase* v_test_case = tcase_create("valid_roman_numeral test cases");
	
	// add our valid_roman_numeral test(s) to the test case
#if 0
	tcase_add_test(v_test_case, test_validate_roman_numeral_one);
	tcase_add_test(v_test_case, test_validate_roman_numeral_two);
	tcase_add_test(v_test_case, test_validate_roman_numeral_three);
	tcase_add_test(v_test_case, test_validate_roman_numeral_bad_four);
	tcase_add_test(v_test_case, test_validate_roman_numeral_five);
	tcase_add_test(v_test_case, test_validate_roman_numeral_bad_ten);
#endif
	tcase_add_test(v_test_case, test_validate_roman_numeral_nine);
	tcase_add_test(v_test_case, test_validate_roman_numeral_ID);
	tcase_add_test(v_test_case, test_validate_roman_numeral_LM);
	tcase_add_test(v_test_case, test_validate_roman_numeral_CM);
	tcase_add_test(v_test_case, test_validate_roman_numeral_XC);
	
	// add the test suite we want
	suite_add_tcase(suite, v_test_case);

	// set up an SRunner to track the state of our tests
	SRunner* state_runner = srunner_create(suite);
	
	// run all tests
	srunner_run_all(state_runner, CK_VERBOSE);
	uint32_t tests_failed = srunner_ntests_failed(state_runner);

	return tests_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
