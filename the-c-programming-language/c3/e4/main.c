// Exercise 3-4: In a two's complement number representation, the provided
// version of itoa does not handle the largest negative number
// -2^(wordsize - 1). Explain why and modify it to print the value correctly,
// regardless of the underlying machine.

#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAXBUF 64

int	get_num(char s[], int maxbuf);
int	atoi(char s[]);
void	itoa_orig(int n, char s[]);
void	itoa_new(int n, char s[]);
void	reverse(char s[]);

int main()
{
	int	len, xo, xn;
	char	s[MAXBUF], so[MAXBUF], sn[MAXBUF];

	printf("Integer miniumum value: %d\n", INT_MIN);

	while (len = get_num(s, MAXBUF)) {
		xo = atoi(s);
		xn = xo;

		itoa_orig(xo, so);
		printf("X value (itoa original): (int)%d - (str)%s\n", xo, so);

		itoa_new(xn, sn);
		printf("X value (itoa new): (int)%d - (str)%s\n", xn, sn);
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

void itoa_orig(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	reverse(s);
	return;
}

void itoa_new(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0) {
		if (n == INT_MIN)
			n = -n - 1;
		else
			n = -n;
	}

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[0]++;
		s[i++] = '-';
	s[i] = '\0';

	reverse(s);
	return;
}

void reverse(char s[])
{
	int l, i, j, bgn, off, bnd;

	l = strlen(s);
	bgn = 0;
	off = 1;

	if (s[0] == '-') {
		bgn = 1;
		off = 0;
	}

	bnd = (l + bgn) / 2;
	for (i = bgn; i < bnd; i++) {
		j = l - i - off;

		s[i] ^= s[j];
		s[j] ^= s[i];
		s[i] ^= s[j];
	}
}

