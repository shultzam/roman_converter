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

START_TEST(test_convert_roman_five_to_arrabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("V"), 5);
}
END_TEST

START_TEST(test_convert_roman_ten_to_arrabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("X"), 10);
}
END_TEST

START_TEST(test_convert_roman_fifty_to_arrabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("L"), 50);
}
END_TEST

START_TEST(test_convert_roman_hundred_to_arrabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("C"), 100);
}
END_TEST

START_TEST(test_convert_roman_fivehundred_to_arrabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("D"), 500);
}
END_TEST

START_TEST(test_convert_roman_thousand_to_arrabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("M"), 1000);
}
END_TEST

#endif	// __TESTS_H__