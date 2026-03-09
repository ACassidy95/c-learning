// Exercise 2-6: Write a function setbits(x, p, n, y) that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving the
// other bits unchanged.

#include <stdio.h>

#define MAXBUF	32

int setbits(int x, int p, int n, int y);
int get_num(char s[], int max);
int atoi(char s[]);

int main()
{
	int lx, ly, lp, ln, x, y, p, n, res;
	char sx[MAXBUF], sy[MAXBUF], sp[4], sn[4];

	printf("Input x value: ");
	lx = get_num(sx, MAXBUF);

	printf("Input y value: ");
	ly = get_num(sy, MAXBUF);

	printf("Input x position: ");
	lp = get_num (sp, 4);

	printf("Input n: ");
	ln = get_num (sn, 4);

	while (lx > 0 && ly > 0 && lp > 0 && ln > 0) {
		x = atoi(sx);
		y = atoi(sy);
		p = atoi(sp);
		n = atoi(sn);

		res = setbits(x, p, n, y);

		printf("X:%12d\nY:%12d\np:%12d\nn:%12d\nres:%10d\n",
		       x, y, p, n, res);

		printf("Input x value: ");
		lx = get_num(sx, MAXBUF);

		printf("Input y value: ");
		ly = get_num(sy, MAXBUF);

		printf("Input x position: ");
		lp = get_num(sp, 4);

		printf("Input n: ");
		ln = get_num(sn, 4);
	}

	return 0;
}

int setbits(int x, int p, int n, int y)
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
