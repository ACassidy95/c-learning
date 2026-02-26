// Exercise 1-4: Write a program to print the corresponding Celsius to
// Fahrenheit table

#include <stdio.h>

int main()
{
	float fahr, cels;
	float lower, upper, step;

        lower	= 0;
	upper	= 300;
	step	= 20;
	cels	= lower;

	printf("%3c %6c\n", 'C', 'F');
	while (fahr <= upper) {
		fahr = ((9.0 * cels) / 5.0) + 32;
		printf("%3.0f %6.1f\n", cels, fahr);
		cels = cels + step;
	}
}

