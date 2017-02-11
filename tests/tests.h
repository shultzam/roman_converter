#ifndef __TESTS_H_
#define __TESTS_H__

#include "converter.h"

// R to A TEST CASES
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

START_TEST(test_convert_roman_three_to_arrabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("III"), 3);
}
END_TEST

// VALIDATE TEST CASES
START_TEST(test_validate_roman_numeral_one)
{
	ck_assert_int_eq(valid_roman_numeral("I"), 1);
}
END_TEST

START_TEST(test_validate_roman_numeral_two)
{
	ck_assert_int_eq(valid_roman_numeral("II"), 1);
}
END_TEST

START_TEST(test_validate_roman_numeral_three)
{
	ck_assert_int_eq(valid_roman_numeral("III"), 1);
}
END_TEST

START_TEST(test_validate_roman_numeral_bad_four)
{
	ck_assert_int_eq(valid_roman_numeral("IIII"), 0);
}
END_TEST

START_TEST(test_validate_roman_numeral_five)
{
	ck_assert_int_eq(valid_roman_numeral("V"), 1);
}
END_TEST

START_TEST(test_validate_roman_numeral_bad_ten)
{
	ck_assert_int_eq(valid_roman_numeral("VVV"), 0);
}
END_TEST

#endif	// __TESTS_H__