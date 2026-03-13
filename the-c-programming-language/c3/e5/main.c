// Exercise 3-5: Write a function itob(n, s, b) that converts the integer n into
// a base b character representation in the string s. In particular itob(n,s,16)
// formats s as a hexadecimal integer in s.

#include <stdio.h>
#include <string.h>

#define MAX_BUF		1024
#define MIN_BASE	2
#define MAX_BASE	16

int	get_num(char s[], int maxbuf);
int	atoi(char s[]);
void	itob(int x, char s[], int base);
void	itobnc(int x, char s[], int base);
int	abs(int x);

int main()
{
	int	len, x, b;
	char	s[MAX_BUF], sb[MAX_BUF], sbnc[MAX_BUF];

	printf("Enter an integer value\n$> ");
	while (len = get_num(s, MAX_BUF)) {
		x = atoi(s);

		for (b = MIN_BASE; b <= MAX_BASE; ++b) {
			itob(x, sb, b);
			itobnc(x, sbnc, b);
			printf("%d in base-%d is: %8s %8s\n", x, b, sb, sbnc);
		}

		printf("$> ");
	}

	return 0;
}

int get_num(char s[], int maxbuf)
{
	int c, i;

	for (i = 0; i < maxbuf - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	s[i] = '\0';
	return i;
}

int atoi(char s[])
{
	int n, i, bgn;

	n = 0;
	bgn = 0;
	if (s[0] == '-')
		bgn = 1;

	for (i = bgn; s[i] != '\0'; ++i)
		n = (n * 10) + (s[i] - '0');

	if (bgn)
		n = -n;

	return n;
}

void itob(int x, char s[], int base)
{
	int bx, i, lb, nd, cd;

	bx = x;
	lb = 1;
	nd = 1;

	// Find the least nearest power of base to x, i.e.
	// b^(n+1) > x >= b^n
	while (lb < bx) {
		lb *= base;
		++nd;
	}

	if (lb > bx) {
		lb /= base;
		--nd;
	}

	for (i = 0; i < nd; ++i) {
		s[i] = '0';
		while (bx >= lb) {
			s[i] += 1;
			bx -= lb;
		}

		if (s[i] > '9') {
			cd = s[i] - '9' - 1;
			s[i] = 'A' + cd;
		}

		lb /= base;
	}
	s[i] = '\0';
}

void itobnc(int x, char s[], int base)
{
	int i;

	// lb - lower bound - Nearest power of base b not greater than x
	// nd - number of digits - Number of digits in str repr of x in base b
	int lb, nd, sign;

	// bmax - Representation of max value in base B used to calculate B's
	// complement for base B
	// bcomp - B's complement representation of x, calculated as digitwise
	// bmax - x
	char bmax[MAX_BUF];
	char bcomp[MAX_BUF];

	nd = 1;
	lb = 1;

	if ((sign = x) < 0) {
		x = -x;
	}

	while (lb < x) {
		lb *= base;
		++nd;
	}

	if (lb > x) {
		lb /= base;
		--nd;
	}

	for (i = 0; i < nd; ++i) {
		bmax[i] = '0' + (base - 1);
		if (bmax[i] > '9') {
			bmax[i] = 'A' + (bmax[i] - '9' - 1);
		}
	}

	for (i = 0; i < nd; ++i) {
		s[i] = '0';

		while (x >= lb) {
			s[i] += 1;
			x -= lb;
		}

		if (s[i] > '9') {
			s[i] = 'A' + (s[i] - '9' - 1);
		}

		lb /= base;
	}

	char d;
	// If the input number was negative, calculate the number's
	// representation in B's complement for the given base B.
	if (sign < 0) {
		for(i = nd - 1; i >= 0; --i) {
			d = bmax[i] - s[i];

			if (d <= 9 || d >= 'A' - '0')
				bcomp[i] = '0' + d;
			else
				bcomp[i] = '0' + (d % 10);
		}

		for (i = 0; i < nd; ++i)
			s[i] = bcomp[i];
	}
	s[i] = '\0';
}

int abs(int x)
{
	int a;

	a = x;
	if (a < 0)
		a = -a;

	return a;
}
