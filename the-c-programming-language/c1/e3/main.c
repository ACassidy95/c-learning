// Exercise 1-3: Modify the temperature conversion program to print a heading
// above the table

#include <stdio.h>

int main()
{
	float fahr, cels;
	float lower, upper, step;

        lower	= 0;
	upper	= 300;
	step	= 20;
	fahr	= lower;

	printf("%3c %6c\n", 'F', 'C');
	while (fahr <= upper) {
		cels = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, cels);
		fahr = fahr + step;
	}
}

