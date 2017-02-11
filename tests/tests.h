#ifndef __TESTS_H_
#define __TESTS_H__

#include "converter.h"

// R to A TEST CASES
START_TEST(test_convert_roman_one_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("I"), 1);
}
END_TEST

START_TEST(test_convert_roman_two_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("II"), 2);
}
END_TEST

START_TEST(test_convert_roman_four_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("IV"), 4);
}
END_TEST

START_TEST(test_convert_roman_five_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("V"), 5);
}
END_TEST

START_TEST(test_convert_roman_ten_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("X"), 10);
}
END_TEST

START_TEST(test_convert_roman_twelve_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("XII"), 12);
}
END_TEST

START_TEST(test_convert_roman_fifteen_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("XV"), 15);
}
END_TEST

START_TEST(test_convert_roman_twentyoneto_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("XXI"), 21);
}
END_TEST

START_TEST(test_convert_roman_forty_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("XL"), 40);
}
END_TEST

START_TEST(test_convert_roman_fifty_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("L"), 50);
}
END_TEST

START_TEST(test_convert_roman_hundred_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("C"), 100);
}
END_TEST

START_TEST(test_convert_roman_fivehundred_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("D"), 500);
}
END_TEST

START_TEST(test_convert_roman_thousand_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("M"), 1000);
}
END_TEST

START_TEST(test_convert_roman_three_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("III"), 3);
}
END_TEST

START_TEST(test_convert_roman_1744_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("MDCCXLIV"), 1744);
}
END_TEST

START_TEST(test_convert_roman_3723_to_arabic)
{
	ck_assert_int_eq(convert_roman_to_arabic("MMMDCCXXIII"), 3723);
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

START_TEST(test_validate_roman_numeral_nine)
{
	ck_assert_int_eq(valid_roman_numeral("IX"), 1);
}
END_TEST

START_TEST(test_validate_roman_numeral_ID)
{
	ck_assert_int_eq(valid_roman_numeral("ID"), 0);
}
END_TEST

START_TEST(test_validate_roman_numeral_LM)
{
	ck_assert_int_eq(valid_roman_numeral("LM"), 0);
}
END_TEST

START_TEST(test_validate_roman_numeral_CM)
{
	ck_assert_int_eq(valid_roman_numeral("CM"), 1);
}
END_TEST

START_TEST(test_validate_roman_numeral_XC)
{
	ck_assert_int_eq(valid_roman_numeral("XC"), 1);
}
END_TEST

// CHARACTER TO VALUE TESTS
START_TEST(test_roman_char_to_value_I)
{
	ck_assert_int_eq(convert_roman_to_value('I'), 1);
}
END_TEST

START_TEST(test_roman_char_to_value_L)
{
	ck_assert_int_eq(convert_roman_to_value('L'), 50);
}
END_TEST

START_TEST(test_roman_char_to_value_C)
{
	ck_assert_int_eq(convert_roman_to_value('C'), 100);
}
END_TEST

START_TEST(test_roman_char_to_value_D)
{
	ck_assert_int_eq(convert_roman_to_value('D'), 500);
}
END_TEST

START_TEST(test_roman_char_to_value_M)
{
	ck_assert_int_eq(convert_roman_to_value('M'), 1000);
}
END_TEST

START_TEST(test_roman_char_to_value_F)
{
	ck_assert_int_eq(convert_roman_to_value('F'), 0);
}
END_TEST

// ARABIC TO ROMAN TESTS
START_TEST(test_value_to_roman_char_1)
{
	ck_assert_str_eq(convert_arabic_to_roman(1), "I");
}
END_TEST

START_TEST(test_value_to_roman_char_4)
{
	ck_assert_str_eq(convert_arabic_to_roman(4), "IV");
}
END_TEST

START_TEST(test_value_to_roman_char_5)
{
	ck_assert_str_eq(convert_arabic_to_roman(5), "V");
}
END_TEST

START_TEST(test_value_to_roman_char_9)
{
	ck_assert_str_eq(convert_arabic_to_roman(9), "IX");
}
END_TEST

START_TEST(test_value_to_roman_char_10)
{
	ck_assert_str_eq(convert_arabic_to_roman(10), "X");
}
END_TEST

START_TEST(test_value_to_roman_char_20)
{
	ck_assert_str_eq(convert_arabic_to_roman(20), "XX");
}
END_TEST

START_TEST(test_value_to_roman_char_40)
{
	ck_assert_str_eq(convert_arabic_to_roman(40), "XL");
}
END_TEST

START_TEST(test_value_to_roman_char_45)
{
	ck_assert_str_eq(convert_arabic_to_roman(45), "XLV");
}
END_TEST

START_TEST(test_value_to_roman_char_50)
{
	ck_assert_str_eq(convert_arabic_to_roman(50), "L");
}
END_TEST

START_TEST(test_value_to_roman_char_90)
{
	ck_assert_str_eq(convert_arabic_to_roman(90), "XC");
}
END_TEST

START_TEST(test_value_to_roman_char_100)
{
	ck_assert_str_eq(convert_arabic_to_roman(100), "C");
}
END_TEST

START_TEST(test_value_to_roman_char_200)
{
	ck_assert_str_eq(convert_arabic_to_roman(200), "CC");
}
END_TEST

START_TEST(test_value_to_roman_char_250)
{
	ck_assert_str_eq(convert_arabic_to_roman(250), "CCL");
}
END_TEST

START_TEST(test_value_to_roman_char_275)
{
	ck_assert_str_eq(convert_arabic_to_roman(275), "CCLXXV");
}
END_TEST

START_TEST(test_value_to_roman_char_400)
{
	ck_assert_str_eq(convert_arabic_to_roman(400), "CD");
}
END_TEST

START_TEST(test_value_to_roman_char_490)
{
	ck_assert_str_eq(convert_arabic_to_roman(490), "CDXC");
}
END_TEST

START_TEST(test_value_to_roman_char_500)
{
	ck_assert_str_eq(convert_arabic_to_roman(500), "D");
}
END_TEST

START_TEST(test_value_to_roman_char_900)
{
	ck_assert_str_eq(convert_arabic_to_roman(900), "CM");
}
END_TEST

START_TEST(test_value_to_roman_char_1000)
{
	ck_assert_str_eq(convert_arabic_to_roman(1000), "M");
}
END_TEST

START_TEST(test_value_to_roman_char_2000)
{
	ck_assert_str_eq(convert_arabic_to_roman(2000), "MM");
}
END_TEST

// DOUBLE CONVERSION TEST CASES
START_TEST(test_double_convert_1)
{
	ck_assert_int_eq(temp_double_conversion_test(1), 1);
}
END_TEST

START_TEST(test_double_convert_2)
{
	ck_assert_int_eq(temp_double_conversion_test(2), 1);
}
END_TEST

START_TEST(test_double_convert_4)
{
	ck_assert_int_eq(temp_double_conversion_test(4), 1);
}
END_TEST

START_TEST(test_double_convert_15)
{
	ck_assert_int_eq(temp_double_conversion_test(15), 1);
}
END_TEST

START_TEST(test_double_convert_300)
{
	ck_assert_int_eq(temp_double_conversion_test(300), 1);
}
END_TEST

START_TEST(test_double_convert_180)
{
	ck_assert_int_eq(temp_double_conversion_test(180), 1);
}
END_TEST

START_TEST(test_double_convert_131)
{
	ck_assert_int_eq(temp_double_conversion_test(131), 1);
}
END_TEST

START_TEST(test_double_convert_420)
{
	ck_assert_int_eq(temp_double_conversion_test(420), 1);
}
END_TEST

START_TEST(add_two_roman_1_1)
{
	ck_assert_str_eq(add_two_roman_values("I", "I"), "II");
}
END_TEST

START_TEST(add_two_roman_1_2)
{
	ck_assert_str_eq(add_two_roman_values("I", "II"), "III");
}
END_TEST

#endif	// __TESTS_H__