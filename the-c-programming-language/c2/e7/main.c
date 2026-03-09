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
	int	lx, ln, lp, x, n, p, res;
	char	sx[MAXBUF], sn[PARAMBUF], sp[PARAMBUF];

	printf("Input x value: ");
	lx = get_num(sx, MAXBUF);

	printf("Input x bitposition: ");
	lp = get_num(sp, PARAMBUF);

	printf("Input bit width n: ");
	ln = get_num(sn, PARAMBUF);

	x = atoi(sx);
	p = atoi(sp);
	n = atoi(sn);

	while (lx > 0 && lp > 0 && ln > 0) {
		res = invert(x, p, n);

		printf("X:%12d\np:%12d\nn:%12d\nres:%10d\n", x, p, n, res);

		printf("Input x value: ");
		lx = get_num(sx, MAXBUF);

		printf("Input x bitposition: ");
		lp = get_num(sp, PARAMBUF);

		printf("Input bit width n: ");
		ln = get_num(sn, PARAMBUF);

		x = atoi(sx);
		p = atoi(sp);
		n = atoi(sn);
	}

	return 0;
}

int get_num(char s[], int max)
{
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	// Discard any newline as irrelevant to program
	s[i] = '\0';
	return i;
}

int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] != '\0'; ++i)
		n = n * 10 + (s[i] - '0');

	return n;
}

int invert(int x, int p, int n)
{
	int xb, xninv;

	// Isolate n bits of x, then shift up to occupy positions p,...,p-(n-1)
	xb = ~(~0 << n);
	xb = xb << (p - n);

	xninv = x ^ xb;

	return xninv;
}
