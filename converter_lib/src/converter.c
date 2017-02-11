#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
			if( roman_input[char_index + 1] == 'V' && roman_input[char_index + 2] == 'V' )
			{	
				printf("*** ERROR: Invalid Roman numeral detected due to 3 consecutive 'V'\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		else if( roman_input[char_index] == 'L' )
		{
			if( roman_input[char_index + 1] == 'L' && roman_input[char_index + 2] == 'L' )
			{	
				printf("*** ERROR: Invalid Roman numeral detected due to 3 consecutive 'L'\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		else if( roman_input[char_index] == 'D' )
		{
			if( roman_input[char_index + 1] == 'D' && roman_input[char_index + 2] == 'D' )
			{	
				printf("*** ERROR: Invalid Roman numeral detected due to 3 consecutive 'D'\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		
		// check for illegal preceding characters
		if( roman_input[char_index] == 'I' )
		{
			if( roman_input[char_index + 1] == 'L' || roman_input[char_index + 1] == 'C' 
			 || roman_input[char_index + 1] == 'D' || roman_input[char_index + 1] == 'M' )
			{
				printf("*** ERROR: Invalid Roman numeral detected due illegal proceding characters\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		
		else if( roman_input[char_index] == 'V' )
		{
			if( roman_input[char_index + 1] == 'L' || roman_input[char_index + 1] == 'C' 
			 || roman_input[char_index + 1] == 'D' || roman_input[char_index + 1] == 'M' )
			{
				printf("*** ERROR: Invalid Roman numeral detected due illegal proceding characters\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		
		else if( roman_input[char_index] == 'V' )
		{
			if( roman_input[char_index + 1] == 'C' 
			 || roman_input[char_index + 1] == 'D' 
			 || roman_input[char_index + 1] == 'M' )
			{
				printf("*** ERROR: Invalid Roman numeral detected due illegal proceding characters\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		
		else if( roman_input[char_index] == 'X' )
		{
			if( roman_input[char_index + 1] == 'D' || roman_input[char_index + 1] == 'M' )
			{
				printf("*** ERROR: Invalid Roman numeral detected due illegal proceding characters\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
		
		else if( roman_input[char_index] == 'L' )
		{
			if( roman_input[char_index + 1] == 'D' || roman_input[char_index + 1] == 'M' )
			{
				printf("*** ERROR: Invalid Roman numeral detected due illegal proceding characters\n"); 
				printf("           Roman numeral received: %s\n", roman_input);
				return 0;
			}
		}
	}
	
	// if nothing failed, it passed
	return 1;
}

// convert Roman numeral character to Arabic value
uint16_t convert_roman_to_value( char roman_char )
{
	switch( roman_char )
	{
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
		default:
			printf("*** WARNING: Invalid character (%c) in %s\n", roman_char, __func__);
			return 0;
	}
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
	
	int32_t sum = 0;		// value to return
	int32_t char_index; 
	char previous  = ' ';
	// check characters right from left
	for( char_index = strlen(roman_input) - 1; char_index >= 0; char_index-- )
	{
		// if the values are getting smaller, right to left and not a duplicate
		// character
		if( convert_roman_to_value(roman_input[char_index]) < sum
		 && roman_input[char_index] != previous )
		{
			sum -= convert_roman_to_value(roman_input[char_index]);
		}
		else
		{
			// otherwise just increment the value
			sum += convert_roman_to_value(roman_input[char_index]);
		}
		
		// update previous character -- this is here instead of just looking at the next char
		// so that we can compare on the first indicie without segfaulting
		previous = roman_input[char_index];
	}
	
	// return the saved value
	return sum;
}

char* convert_arabic_to_roman( int32_t arabic_input )
{
	char roman_string[50];		// string to keep track of what is added
	uint32_t s_index = 0;		// tracks the string index
	uint32_t index;				// for looping through the arabic_input
	
	uint8_t flag = 0;
	while( arabic_input != 0 )
	{
		if( arabic_input >= 1000 )			// value of M
		{
			for( index = 0; index < arabic_input/1000; index++ )
			{
				roman_string[s_index++] = 'M';
			}
			arabic_input = arabic_input - (arabic_input/1000) * 1000; 
		}
		else if( arabic_input >= 500 )		// value of D
		{
			if( arabic_input < 900 )
			{
				for( index = 0; index < arabic_input/500; index++ )
				{
					roman_string[s_index++] = 'D';
				}
				arabic_input = arabic_input - (arabic_input/500) * 500; 
			}
			else
			{
				roman_string[s_index++] = 'C';
				roman_string[s_index++] = 'M';
				arabic_input = arabic_input - 900;
			}
		}
		else if( arabic_input >= 100 )		// value of C
		{
			if( arabic_input < 400 )
			{
				for( index = 0; index < arabic_input/100; index++ )
				{
					roman_string[s_index++] = 'C';
				}
				arabic_input = arabic_input - (arabic_input/100) * 100; 
			}
			else
			{				
				roman_string[s_index++] = 'C';
				roman_string[s_index++] = 'D';
				arabic_input = arabic_input - 400;
			}
		}
		else if( arabic_input >= 50 )		// value of L
		{
			if( arabic_input < 90 )
			{
				if( arabic_input == 90 )
					printf("== arabic_input = %u\n", arabic_input);
				
				for( index = 0; index < arabic_input/50; index++ )
				{
					roman_string[s_index++] = 'L';
				}
				arabic_input = arabic_input - (arabic_input/50) * 50; 
			}
			else
			{
				roman_string[s_index++] = 'X';
				roman_string[s_index++] = 'C';
				arabic_input = arabic_input - 90;
			}
		}
		else if( arabic_input >= 10 )		// value of X
		{
			if( arabic_input < 40 )
			{
				for( index = 0; index < arabic_input/10; index++ )
				{
					roman_string[s_index++] = 'X';
				}
				arabic_input = arabic_input - (arabic_input/10) * 10; 
			}
			else
			{
				roman_string[s_index++] = 'X';
				roman_string[s_index++] = 'L';
				arabic_input = arabic_input - 40;
			}
		}
		else if( arabic_input >= 5 )		// value of V
		{
			if( arabic_input < 9 )
			{
				for( index = 0; index < arabic_input/5; index++ )
				{
					roman_string[s_index++] = 'V';
				}
				arabic_input = arabic_input - (arabic_input/5) * 5; 
			}
			else
			{
				roman_string[s_index++] = 'I';
				roman_string[s_index++] = 'X';
				arabic_input = arabic_input - 9;
			}
		}
		else if( arabic_input >= 1 )		// value of I
		{
			if( arabic_input < 4 )
			{
				for( index = 0; index < arabic_input; index++ )
				{
					roman_string[s_index++] = 'I';
				}
				arabic_input = arabic_input - arabic_input; 
			}
			else
			{
				roman_string[s_index++] = 'I';
				roman_string[s_index++] = 'V';
				arabic_input = arabic_input - 4;
			}
		}
	}
	
	// recreate the return string as a char*
	char* return_string = (char* )malloc(strlen(roman_string) + 1);
	strcpy(return_string, roman_string);
	
	// return our roman_string
	return return_string;
}

// test function to be used for verifying Arabic -> Roman -> Arabic
uint8_t temp_double_conversion_test( uint32_t arabic_input )
{
	char*   roman_output = convert_arabic_to_roman(arabic_input);
	int32_t arabic_output = convert_roman_to_arabic(roman_output);
	
	if( arabic_output != arabic_input )
	{
		printf("*** WARNING: Conversion checks in %s failed\n", __func__ );
		printf("    arabic_input  = %u\n", arabic_input);
		printf("    roman_output  = %s\n", roman_output);
		printf("    arabic_output = %u\n", arabic_output);
		return 0;
	}
	
	return 1;
}