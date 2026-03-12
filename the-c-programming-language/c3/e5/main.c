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
void	itob(int n, char s[], int base);

int main()
{
	int	len, x, b;
	char	s[MAX_BUF], sb[MAX_BUF];

	printf("Enter an integer value\n$> ");
	while (len = get_num(s, MAX_BUF)) {
		x = atoi(s);

		for (b = MIN_BASE; b <= MAX_BASE; ++b) {
			itob(x, sb, b);
			printf("%d in base-%d is: %s\n", x, b, sb);
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

