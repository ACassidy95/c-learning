// Exercise 2-8: Write a function rightrot(x, n) that returns the value of x
// rotated by n positions

#include <stdio.h>

#define MAXBUF	32

int get_num(char s[], int max);
int atoi(char s[]);
int rightrot(int x, int n);

int main()
{
	int lx, ln, x, n, res;
	char sx[MAXBUF], sn[MAXBUF];

	printf("Input x value: ");
	lx = get_num(sx, MAXBUF);

	printf("Input rotation value: ");
	ln = get_num(sn, MAXBUF);

	x = atoi(sx);
	n = atoi(sn);

	while (lx > 0 && ln > 0) {
		res = rightrot(x, n);

		printf("X:%10d\nn:%10d\nres: %8d\n", x, n, res);

		printf("Input x value: ");
		lx = get_num(sx, MAXBUF);

		printf("Input rotation value: ");
		ln = get_num(sn, MAXBUF);

		x = atoi(sx);
		n = atoi(sn);
	}

	return 0;
}

int get_num(char s[], int max)
{
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

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

int rightrot(int x, int n)
{
	int i, mx, mxn, xrot;

	// Find max 100... bit sequence for int type
	mx = 1;
	mxn = mx << 1;
	while (mx < mxn) {
		mx << 1;
		mxn << 1;
	}

	for (i = 0; i < n; ++i) {
		if (x % 2) {
			xrot = x >> 1;
		} else {
			xrot = x >> 1;
			xrot &= mx;
		}
	}

	return xrot;
}
