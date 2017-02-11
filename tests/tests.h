#ifndef __TESTS_H_
#define __TESTS_H__

#include "converter.h"

START_TEST(test_convert_roman_one_to_arrabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("I"), 1);
}
END_TEST

START_TEST(test_convert_roman_two_to_arrabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("II"), 2);
}
END_TEST

#endif	// __TESTS_H__