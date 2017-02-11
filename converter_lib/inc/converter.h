#ifndef __CONVERTER_H__
#define __CONVERTER_H__

#include <stdint.h>

// add and subtract functions
char*    add_two_roman_values(char* roman_val_1, char* roman_val_2);
char*    subtract_two_roman_values(char* roman_val_1, char* roman_val_2);

// utility functions
int32_t  convert_roman_to_arabic( char* roman_input );
uint16_t convert_roman_to_value( char roman_char );
int8_t   valid_roman_numeral( char* roman_input );

char*    convert_arabic_to_roman( int32_t arabic_input );

uint8_t  temp_double_conversion_test( uint32_t arabic_input );

#endif	// __CONVERTER_H__