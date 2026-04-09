// Exercise 4.12: Write a recursive version of itoa, that is, convert an integer
// to a string by recursive calls to the routine itoa.

#include <limits.h>
#include <stdio.h>

void ritoa(int n);

int main(void)
{
	int m, n;

	m = 1234;
	n = -9876;

	printf("m - %d\n", m);
	ritoa(m);
	printf("\nn - %d\n", n);
	ritoa(n);
	printf("\n");

	return 0;
}

void ritoa(int n)
{
	int c, sign;

	if ((sign = n) < 0) {
		putchar('-');
		if (n == INT_MIN)
			n = -n - 1;
		else
			n = -n;
	}

	c = n % 10 + '0';
	putchar(c);
	if (n / 10)
		ritoa(n / 10);

	return;
}

