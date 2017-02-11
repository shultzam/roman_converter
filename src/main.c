#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "converter.h"

/*
 * main serves as a driver that pushes Check test cases
 */

int main( int argc, char* argv[])
{
	int32_t result = convert_roman_to_arabic("XX");
	printf("result = %d\n", result);
	
	return EXIT_SUCCESS;
}
