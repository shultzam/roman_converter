#ifndef __CONVERTER_H__
#define __CONVERTER_H__

#include <stdint.h>

int32_t  convert_roman_to_arabic( char* roman_input );
uint16_t convert_roman_to_value( char roman_char );
int8_t   valid_roman_numeral( char* roman_input );

char*   convert_arabic_to_roman( int32_t arabic_input );

#endif	// __CONVERTER_H__