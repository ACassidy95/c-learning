// Exercise 1-15: Rewrite the temperature conversion program to use a function
// for conversion

#include <stdio.h>

#define	MIN	-100
#define MAX	100
#define STEP	10

float ftoc(float fahr);
float ctof(float cels);

int main()
{
	float val;

	printf("%10c%10c%10c%10c\n", 'F', 'C', 'C', 'F');
	for (val = MIN; val <= MAX; val = val + STEP) {
		printf("%10.0f%10.1f%10.0f%10.1f\n",
		       val, ftoc(val), val, ctof(val));
	}
}

float ftoc(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
}

float ctof(float cels)
{
	return ((9.0 * cels) / 5.0) + 32.0;
}
