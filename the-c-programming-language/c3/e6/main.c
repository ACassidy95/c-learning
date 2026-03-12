// Exercise 3-6: Write a version of itoa that accepts three arguments instead of
// two. The third argument is a miniumum field width; the converted nmuber must
// be padded with blanks on the left if necessary to make it wide enough.

#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUF 8

int	get_num(char s[], int max);
int	atoi(char s[]);
void	reverse(char s[]);
void	itoaw(int x, char s[], unsigned w);

int main()
{
	int	len, x;
	char	s[MAX_BUF];

	while ((len = get_num(s, MAX_BUF)) > 0) {
		x = atoi(s);
		itoaw(x, s, MAX_BUF);
		printf("%s\n", s);
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
	int n, i;
	int sidx;

	sidx = 0;
	if (s[0] == '-')
		sidx = 1;

	n = 0;
	for (i = sidx; s[i] != '\0'; ++i)
		n = (n * 10) + (s[i] - '0');

	if (sidx)
		n = -n;

	return n;
}

void reverse(char s[])
{
	int i, l, len, off, bnd;

	i = 0;
	off = 1;
	if (s[0] == '-') {
		i = 1;
		off = 0;
	}

	len = strlen(s);
	bnd = (len + i) / 2;
	for (i; i < bnd; ++i) {
		l = len - i - off;

		s[i] ^= s[l];
		s[l] ^= s[i];
		s[i] ^= s[l];
	}
}

void itoaw(int x, char s[], unsigned w)
{
	int i, sign;

	if ((sign = x) < 0) {
		if (x == INT_MIN)
			x = -x - 1;
		else
			x = -x;
	}

	i = 0;
	do {
		s[i++] = x % 10 + '0';
	} while ((x /= 10) > 0);

	if (sign < 0) {
		s[i++] = '-';
	}

	while (i < w)
		s[i++] = '.';

	s[i] = '\0';
	reverse(s);

	return;
}
