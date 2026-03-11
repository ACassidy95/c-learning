// Exercise 3-4: In a two's complement number representation, the provided
// version of itoa does not handle the largest negative number
// -2^(wordsize - 1). Explain why and modify it to print the value correctly,
// regardless of the underlying machine.

#include <stdio.h>

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

	while ((len = get_num(s, MAXBUF)) > 0) {
		xo = atoi(s);
		xn = xo;

		itoa_orig(xo, so);
		printf("X value (itoa original): %d\n", xo);

		itoa_new(xn, sn);
		printf("X value (itoa new): %d\n", xn);
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
	int n, i;

	n = 0;
	for (i = 0; s[i] != '\0'; ++i)
		n = (n * 10) + (s[i] - '0');

	return n;
}

void itoa_orig(int n, char s[])
{
	return;
}

void itoa_new(int n, char s[])
{
	return;
}
