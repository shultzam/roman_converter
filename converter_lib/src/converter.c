#include <stdio.h>
#include <string.h>

#include "converter.h"

// converts a given string of roman numerals into an integer
int32_t convert_roman_to_arabic( char* roman_input )
{
	int32_t value = 0;		// value to return
	
	uint16_t char_index;
	// compare each character of the input string
	for( char_index = 0; char_index < strlen(roman_input); char_index++ )
	{
		// compare each character of the input string
		if( roman_input[char_index] == 'I' )
		{
			value += 1;
		}
		else if( roman_input[char_index] == 'V' )
		{
			value += 5;
		}
		else if( roman_input[char_index] == 'X' )
		{
			value += 10;
		}
		else if( roman_input[char_index] == 'L' )
		{
			value += 50;
		}
		else if( roman_input[char_index] == 'C' )
		{
			value += 100;
		}
		else if( roman_input[char_index] == 'D' )
		{
			value += 500;
		}
		else if( roman_input[char_index] == 'M' )
		{
			value += 1000;
		}
		else
		{
			printf("*** WARNING: Unknown input: %s\n", roman_input);
			return 0;
		}
	}
		
	// return the saved value
	return value;
}