// Exercise 2-1a: Write a program to determine the ranges of char, short, int,
// and long variables, both signed and unsigned by printing appropriate values
// from standard headers

#include <stdio.h>
#include <limits.h>

int main()
{
	printf("Unsigned min: %+10d\n\n", 0);

	printf("Unsigned char max: %+10d\n", UCHAR_MAX);
	printf("Signed char min: %+10d\n", SCHAR_MIN);
	printf("Signed char max: %+10d\n\n", SCHAR_MAX);

	printf("Unsigned short max: %+10d\n", USHRT_MAX);
	printf("Signed short min: %+10d\n", SHRT_MIN);
	printf("Signed short max: %+10d\n\n", SHRT_MAX);

	printf("Unsigned int max: %+10u\n", UINT_MAX);
	printf("Signed int min: %+10d\n", INT_MIN);
	printf("Signed int max: %+10d\n\n", INT_MAX);

	printf("Unsigned long int max: %+10lu\n", ULONG_MAX);
	printf("Signed long int min: %+10ld\n", LONG_MIN);
	printf("Signed long int max: %+10ld\n\n", LONG_MAX);

	return 0;
}
