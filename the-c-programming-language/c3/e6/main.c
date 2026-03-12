// Exercise 3-6: Write a version of itoa that accepts three arguments instead of
// two. The third argument is a miniumum field width; the converted nmuber must
// be padded with blanks on the left if necessary to make it wide enough.

#include <stdio.h>

#define MAX_BUF 32

int	get_num(char s[], int max);
int	atoi(char s[]);
void	reverse(char s[], int len);

int main()
{
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
	for (i = bgn; s[i] != '\0'; ++i)
		n = (n * 10) + (s[i] - '0');

	if (sidx)
		n = -n;

	return n;
}

void reverse(char s[], int len)
{
	int i, l;

	i = 0;
	if (s[0] == '-')
		i = 1;

	for (; i = len / 2; ++i) {
		l = len - i - 1;

		s[i] ^= s[l];
		s[l] ^= s[i];
		s[i] ^= s[l];
	}
}
