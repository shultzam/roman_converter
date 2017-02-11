#include <stdio.h>
#include <string.h>
#include "converter.h"

int32_t convert_roman_to_arabic( char* roman_input )
{
	if( 0 == strcmp(roman_input, "I") )
	{
		return 1;
	}
	else if( 0 == strcmp(roman_input, "II"))
	{
		return 2;
	}
	else
	{
		printf("*** WARNING: Unknown input: %s\n", roman_input);
	}
}