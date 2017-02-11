#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <ctype.h>
#include <check.h>

#include "tests.h"

#define TEST_ROMAN_TO_ARABIC	1
#define TEST_VALID_ROMAN		2
#define TEST_VALUE_OF_ROMAN		4
#define TEST_ARABIC_TO_ROMAN	8
#define TEST_DBL_CONVERSIONS	16
#define TEST_ADDITIONS			32
#define TEST_SUBTRACTIONS		64

/*
 * main serves as a driver that pushes Check test cases
 */

int main( int argc, char* argv[])
{
	// determine what tests will be executed
	uint8_t arg;
	uint32_t tests_to_run = 0;
	for( arg = 0; arg < argc; arg++ )
	{
		if( strcmp( "ALL", argv[arg]) == 0 )
		{
			tests_to_run = ~0;
			break;
		}
		else if( strcmp( "ROMAN_TO_ARABIC", argv[arg]) == 0 )
		{
			tests_to_run |= TEST_ROMAN_TO_ARABIC;
		}
		else if( strcmp( "VALID_ROMAN", argv[arg]) == 0 )
		{
			tests_to_run |= TEST_VALID_ROMAN;
		}
		else if( strcmp( "ROMAN_VALUE", argv[arg]) == 0 )
		{
			tests_to_run |= TEST_VALUE_OF_ROMAN;
		}
		else if( strcmp( "ARABIC_TO_ROMAN", argv[arg]) == 0 )
		{
			tests_to_run |= TEST_ARABIC_TO_ROMAN;
		}
		else if( strcmp( "DOUBLE_CONVERSIONS", argv[arg]) == 0 )
		{
			tests_to_run |= TEST_DBL_CONVERSIONS;
		}
		else if( strcmp( "ADDITIONS", argv[arg]) == 0 )
		{
			tests_to_run |= TEST_ADDITIONS;
		}
		else if( strcmp( "SUBTRACTIONS", argv[arg]) == 0 )
		{
			tests_to_run |= TEST_SUBTRACTIONS;
		}
	}
	
	// if no tests are specified, just exit
	if( 0 == tests_to_run )
	{
		printf("No tests specified, defaulting to all tests..\n");
		tests_to_run = ~0;
	}
	
	// create the test suite
	Suite* suite = suite_create("test suite");
	
	// create the Roman to Arabic test case
	TCase* r_t_a_test_case = tcase_create("convert_roman_to_arabic test cases");

	// add our convert_roman_to_arabic test(s) to the test case
	if( tests_to_run & TEST_ROMAN_TO_ARABIC )
	{
		tcase_add_test(r_t_a_test_case, test_convert_roman_one_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_two_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_three_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_four_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_five_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_ten_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_twelve_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_fifteen_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_twentyoneto_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_forty_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_fifty_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_hundred_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_fivehundred_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_thousand_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_1744_to_arabic);
		tcase_add_test(r_t_a_test_case, test_convert_roman_3723_to_arabic);
		
		// add the test suite
		suite_add_tcase(suite, r_t_a_test_case);
	}
	
	// create the validate test case
	TCase* v_test_case = tcase_create("valid_roman_numeral test cases");
	
	// add our validate_roman test(s) to the test case
	if( tests_to_run & TEST_VALID_ROMAN )
	{
		// add our valid_roman_numeral test(s) to the test case
		tcase_add_test(v_test_case, test_validate_roman_numeral_one);
		tcase_add_test(v_test_case, test_validate_roman_numeral_two);
		tcase_add_test(v_test_case, test_validate_roman_numeral_three);
		tcase_add_test(v_test_case, test_validate_roman_numeral_bad_four);
		tcase_add_test(v_test_case, test_validate_roman_numeral_five);
		tcase_add_test(v_test_case, test_validate_roman_numeral_nine);
		tcase_add_test(v_test_case, test_validate_roman_numeral_ID);
		tcase_add_test(v_test_case, test_validate_roman_numeral_LM);
		tcase_add_test(v_test_case, test_validate_roman_numeral_CM);
		tcase_add_test(v_test_case, test_validate_roman_numeral_XC);
		
		// add the test suite
		suite_add_tcase(suite, v_test_case);
	}
	
	// create the validate test caseS
	TCase* value_test_case = tcase_create("value of char test cases");
	
	// add our value of Roman numerals test(s) to the test case
	if( tests_to_run & TEST_VALUE_OF_ROMAN )
	{
		tcase_add_test(value_test_case, test_roman_char_to_value_I);
		tcase_add_test(value_test_case, test_roman_char_to_value_L);
		tcase_add_test(value_test_case, test_roman_char_to_value_C);
		tcase_add_test(value_test_case, test_roman_char_to_value_D);
		tcase_add_test(value_test_case, test_roman_char_to_value_M);
		tcase_add_test(value_test_case, test_roman_char_to_value_F);
		
		// add the test suite
		suite_add_tcase(suite, value_test_case);
	}
	
	// create the Arabic to Roman test cases
	TCase* a_t_r_test_case = tcase_create("Arabic to Roman test cases");
	
	// add our arabic_to_roman test(s) to the test case
	if( tests_to_run & TEST_ARABIC_TO_ROMAN )
	{
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_1);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_4);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_5);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_9);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_10);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_20);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_40);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_45);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_50);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_90);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_100);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_200);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_250);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_275);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_400);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_490);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_500);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_900);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_1000);
		tcase_add_test(a_t_r_test_case, test_value_to_roman_char_2000);
		
		// add the test suite
		suite_add_tcase(suite, a_t_r_test_case);
	}
	
	// create the Arabic to Roman test cases
	TCase* dbl_conversion_test_case = tcase_create("Arabic to Roman to Arabic test cases");
	
	// add our double_conversion test(s) to the test case
	if( tests_to_run & TEST_DBL_CONVERSIONS )
	{
		tcase_add_test(dbl_conversion_test_case, test_double_convert_1);
		tcase_add_test(dbl_conversion_test_case, test_double_convert_2);
		tcase_add_test(dbl_conversion_test_case, test_double_convert_4);
		tcase_add_test(dbl_conversion_test_case, test_double_convert_15);
		tcase_add_test(dbl_conversion_test_case, test_double_convert_300);
		tcase_add_test(dbl_conversion_test_case, test_double_convert_180);
		tcase_add_test(dbl_conversion_test_case, test_double_convert_131);
		tcase_add_test(dbl_conversion_test_case, test_double_convert_420);
	
		// add the test suite
		suite_add_tcase(suite, dbl_conversion_test_case);
	}

	// create the Arabic to Roman test cases
	TCase* add_test_case = tcase_create("adding Roman test cases");
	
	// add our add_two_roman_values test(s) to the test case
	if( tests_to_run & TEST_ADDITIONS )
	{
		tcase_add_test(add_test_case, add_two_roman_1_1);
		tcase_add_test(add_test_case, add_two_roman_1_2);
		tcase_add_test(add_test_case, add_two_roman_2_1);
		tcase_add_test(add_test_case, add_two_roman_3_3);
		tcase_add_test(add_test_case, add_two_roman_7_4);
		tcase_add_test(add_test_case, add_two_roman_51_22);
		tcase_add_test(add_test_case, add_two_roman_900_50);
		tcase_add_test(add_test_case, add_two_roman_42_99);
		
		// add the test suite
		suite_add_tcase(suite, add_test_case);
	}
	
	// create the Arabic to Roman test cases
	TCase* sub_test_case = tcase_create("subtracting Roman test cases");
	
	// add our sub_two_roman_values test(s) to the test case
	if( tests_to_run & TEST_SUBTRACTIONS )
	{
		tcase_add_test(sub_test_case, sub_two_roman_2_1);
		tcase_add_test(sub_test_case, sub_two_roman_4_2);
		tcase_add_test(sub_test_case, sub_two_roman_5_2);
		tcase_add_test(sub_test_case, sub_two_roman_10_2);
		tcase_add_test(sub_test_case, sub_two_roman_142_23);
		tcase_add_test(sub_test_case, sub_two_roman_500_498);
		tcase_add_test(sub_test_case, sub_two_roman_450_299);
		
		// add the test suite
		suite_add_tcase(suite, sub_test_case);
	}
	
	// set up an SRunner to track the state of our tests
	SRunner* state_runner = srunner_create(suite);
	
	// run all tests
	srunner_run_all(state_runner, CK_VERBOSE);
	uint32_t tests_failed = srunner_ntests_failed(state_runner);

	return tests_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
