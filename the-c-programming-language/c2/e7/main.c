// Exercise 2-7: Write a function invert(x, p, n) that returns x with the n bits
// that begin at position p inverted leaving the others unchanged.

#include <stdio.h>

#define MAXBUF		32
#define PARAMBUF	4

int get_num(char s[], int max);
int atoi(char s[]);
int invert(int x, int p, int n);

int main()
{
	return 0;
}

int get_num(char s[], int max)
{
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	// Discard any newline as irrelevant to program
	c[i] = '\0';
	return i;
}

int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] != '\0'; ++n)
		n = n * 10 + (s[i] - '0');

	return n;
}
