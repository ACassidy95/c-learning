// Exercise 2-6: Write a function setbits(x, p, n, y) that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving the
// other bits unchanged.

#include <stdio.h>

#define MAXBUF	128

int setbits(int x, int n, int p, int y);
int get_num(char s[], int max);
int atoi(char s[]);

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

int get_num(char s[], int max)
{
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	// Discard any newline
	s[i] = '\0';
	return i;
}

int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] != '\0'; ++i)
		n = 10 * n + (s[i] - '0');

	return n;
}
