#include <ctype.h>
#include <stdio.h>

#define MAXNUM	256

int	getch(void);
int	getint(int *);
void	ungetch(int);

int main(void)
{
	int n, m, ints[MAXNUM];

	for (n = 0; n < MAXNUM && getint(&ints[n]) != EOF; ++n) {
		for (m = 0; m <= n; ++m)
			printf("%8d", ints[m]);
		printf("\n");
	}

	return 0;
}

int getint(int *n)
{
	int c, sign;

	while (isspace(c = getch()))
		;

	// Not a number, sign, or end signal
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();

	for (*n = 0; isdigit(c); c = getch())
		*n = 10 * *n + (c - '0');
	*n *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}

int pushback = -1;

int getch(void)
{
	int c;

	if (pushback != -1) {
		c = pushback;
		pushback = -1;
	} else {
		c = getchar();
	}

	return c;
}

void ungetch(int c)
{
	if (pushback != -1)
		printf("Error - ungetch: character %c waiting\n", pushback);
	else
		pushback = c;
	return;
}
