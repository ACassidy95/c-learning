// Exercise 3-5: Write a function itob(n, s, b) that converts the integer n into
// a base b character representation in the string s. In particular itob(n,s,16)
// formats s as a hexadecimal integer in s.

#include <stdio.h>
#include <string.h>

#define MAX_BUF		32
#define MIN_BASE	2
#define MAX_BASE	16

int	get_num(char s[], int maxbuf);
int	atoi(char s[]);
void	itob(int x, char s[], int base);

// Converts a numeric character in base B to its integer value
int	ctoi(char c);

// Converts an integer value x to its string representation in B's Complement
// for a given base B.
void	itobc(int x, char s[], int base);

// Takes a base B string representation of a negative integer value
// in the string s and repopulates s with the B's Complement representation of
// the same value
void	complement(char s[], int base);

int main()
{
	int	len, x, b;
	char	s[MAX_BUF], sb[MAX_BUF], sbnc[MAX_BUF];

	printf("Enter an integer value\n$> ");
	while (len = get_num(s, MAX_BUF)) {
		x = atoi(s);

		for (b = MIN_BASE; b <= MAX_BASE; ++b) {
			itob(x, sb, b);
			itobc(x, sbnc, b);
			printf("%d in base-%d is: %9s %9s\n", x, b, sb, sbnc);
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
	int i, sign, lb, nd, cd;

	lb = 1;
	nd = 1;

	if ((sign = x) < 0)
		x = -x;

	// Find the least nearest power of base to x, i.e.
	// b^(n+1) > x >= b^n
	while (lb < x) {
		lb *= base;
		++nd;
	}

	if (lb > x) {
		lb /= base;
		--nd;
	}

	s[i] = '0';
	for (i = 1; i <= nd; ++i) {
		s[i] = '0';
		while (x >= lb) {
			s[i] += 1;
			x -= lb;
		}

		if (s[i] > '9') {
			cd = s[i] - '9' - 1;
			s[i] = 'A' + cd;
		}

		lb /= base;
	}

	if (sign < 0)
		s[0] = '-';

	s[i] = '\0';
}

void itobc(int x, char s[], int base)
{
	int i;

	// lb - lower bound - Nearest power of base b not greater than x
	// nd - number of digits - Number of digits in str repr of x in base b
	int lb, nd, sign;

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

	s[0] = '0';
	for (i = 1; i <= nd; ++i) {
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
	s[i] = '\0';

	// If the input number was negative, repopulate the number's
	// representation in B's complement for the given base B
	if (sign < 0)
		complement(s, base);
}

void complement(char s[], int base)
{
	char	bmax, c;
	int	i, cry;

	// Find character for digit representing highest digital value in base
	// B. B's complement is calculated by pairwise s[i] = bmax - s[i] which
	// will end in range 0 - bmax
	bmax = '0' + (base - 1);
	if (bmax > '9')
		bmax = 'A' + (bmax - '9' - 1);

	for (i = 0; s[i] != '\0'; ++i) {
		c = ctoi(bmax) - ctoi(s[i]);
		if (c < 10) {
			s[i] = '0' + c;
		} else {
			s[i] = 'A' + (c % 10);
		}
	}
	s[i] = '\0';

	// Add 1 and carry along up to the sign digit
	cry = 0;
	do {
		--i;
		s[i]++;
		if (s[i] > bmax) {
			cry = 1;
		} else {
			cry = 0;
		}

		if (s[i] > '9')
			s[i] = 'A' + (s[i] - '9' - 1);
	} while (i > 0 && cry);

	return;
}

int ctoi(char c)
{
	int i;

	if (c >= '0' && c <= '9')
		i = c - '0';
	else if (c >= 'A' && c <= 'Z')
		i = 10 + (c - 'A');

	return i;
}
