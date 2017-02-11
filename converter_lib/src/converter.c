#include <stdio.h>
#include <string.h>

#include "converter.h"

// converts a given string of roman numerals into an integer
int32_t convert_roman_to_arabic( char* roman_input )
{
	if( 0 == strcmp(roman_input, "I") )
	{
		return 1;
	}
	else if( 0 == strcmp(roman_input, "V"))
	{
		return 5;
	}
	else if( 0 == strcmp(roman_input, "X"))
	{
		return 10;
	}
	else if( 0 == strcmp(roman_input, "L"))
	{
		return 50;
	}
	else if( 0 == strcmp(roman_input, "C"))
	{
		return 100;
	}
	else if( 0 == strcmp(roman_input, "D"))
	{
		return 500;
	}
	else if( 0 == strcmp(roman_input, "M"))
	{
		return 1000;
	}
	else
	{
		printf("*** WARNING: Unknown input: %s\n", roman_input);
	}
}