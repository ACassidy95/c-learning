// Exercise 2-6: Write a function setbits(x, p, n, y) that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving the
// other bits unchanged.

#include <stdio.h>

#define MAXBUF	128

int setbits(int x, int n, int p, int y);
int get_num(char s[], int max);

int main()
{
	return 0;
}

int setbits(int x, int n, int p, int y)
{
	int ry, sry;

	// isolate rightmost n bits of y
	ry = y & ~(~0 << n);

	// shift isolated y bits to align with position p of x
	sry = ry << (p - n);

	return x | sry;
}
