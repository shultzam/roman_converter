#include <stdio.h>
#include <string.h>

#include "converter.h"

// validates the Roman numeral input string against the Roman numeral rules
int8_t valid_roman_numeral( char* roman_input )
{
	uint16_t char_index;
	for( char_index = 0; char_index < strlen(roman_input); char_index++ )
	{
		// check for 4 consecutive characters of I, X or C
		if( roman_input[char_index] == 'I' )
		{
			if( roman_input[char_index + 1] == 'I' 
			 && roman_input[char_index + 2] == 'I'
			 && roman_input[char_index + 3] == 'I')
			{	
				printf("*** ERROR: Invalid Roman numeral detected due to 3 consecutive 'I'\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		else if( roman_input[char_index] == 'X' )
		{
			if( roman_input[char_index + 1] == 'X' 
			 && roman_input[char_index + 2] == 'X'
			 && roman_input[char_index + 3] == 'X')
			{	
				printf("*** ERROR: Invalid Roman numeral detected due to 3 consecutive 'X'\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		else if( roman_input[char_index] == 'C' )
		{
			if( roman_input[char_index + 1] == 'C' 
			 && roman_input[char_index + 2] == 'C'
			 && roman_input[char_index + 3] == 'C')
			{	
				printf("*** ERROR: Invalid Roman numeral detected due to 3 consecutive 'C'\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		
		// check for 3 consecutive characters of V, L or D
		if( roman_input[char_index] == 'V' )
		{
			if( roman_input[char_index + 1] == 'V' 
			 && roman_input[char_index + 2] == 'V' )
			{	
				printf("*** ERROR: Invalid Roman numeral detected due to 3 consecutive 'V'\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		else if( roman_input[char_index] == 'L' )
		{
			if( roman_input[char_index + 1] == 'L' 
			 && roman_input[char_index + 2] == 'L' )
			{	
				printf("*** ERROR: Invalid Roman numeral detected due to 3 consecutive 'L'\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		else if( roman_input[char_index] == 'D' )
		{
			if( roman_input[char_index + 1] == 'D' 
			 && roman_input[char_index + 2] == 'D' )
			{	
				printf("*** ERROR: Invalid Roman numeral detected due to 3 consecutive 'D'\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
	}
	
	// if nothing failed, it passed
	return 1;
}

// converts a given string of roman numerals into an integer
int32_t convert_roman_to_arabic( char* roman_input )
{
	// validate the input string
	if( !valid_roman_numeral(roman_input) )
	{
		printf("*** WARNING: Invalid input in %s: %s\n", __func__, roman_input);
		return 0;
	}
	
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