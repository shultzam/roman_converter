#ifndef __TESTS_H_
#define __TESTS_H__

#include "converter.h"

START_TEST(test_convert_roman_to_arrabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("I"), 0);
}
END_TEST

#endif	// __TESTS_H__