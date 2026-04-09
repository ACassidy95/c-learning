#include <ctype.h>
#include <math.h>
#include <stdio.h>

#define MAXNUM	6

int	getch(void);
int	getint(int *);
int	getfloat(double *);
void	ungetch(int);

int main(void)
{
	int	n, m, ints[MAXNUM];
	double	doubles[MAXNUM];

	printf("Enter ints:\n");
	for (n = 0; n < MAXNUM && getint(&ints[n]) != EOF; ++n) {
		for (m = 0; m <= n; ++m)
			printf("%8d", ints[m]);
		printf("\n");
	}

	printf("Enter floats:\n");
	for (n = 0; n < MAXNUM && getfloat(&doubles[n]) != EOF; ++n) {
		for (m = 0; m <= n; ++m)
			printf("%8.3lf", doubles[m]);
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
	if (c == '+' || c == '-') {
		while (!isdigit(c = getchar()))
			;
	}

	for (*n = 0; isdigit(c); c = getch())
		*n = 10 * *n + (c - '0');
	*n *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}

int getfloat(double *x)
{
	int	c, sign, expsign, scinot;
	double	base, power, exp;

	scinot = 0;
	while (isspace(c = getch()))
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		while (!isdigit(c = getch()))
			;

	for (*x = 0; isdigit(c); c = getch())
		*x = 10.0 * *x + (c - '0');

	if (c == '.') {
		c = getch();
		for (power = 1.0; isdigit(c); c = getch()) {
			*x = 10.0 * *x + (c - '0');
			power *= 10.0;
		}

		*x = sign * *x / power;
	}

	// Handle scientific notation if it's forthcoming
	if (c == 'e' || c == 'E') {
		c = getch();
		scinot = 1;
	}

	if (scinot) {
		expsign = (c == '-') ? -1 : 1;
		if (c == '+' || c == '-')
			while (!isdigit(c = getch()))
				;

		for (exp = 0; isdigit(c); c = getch())
			exp = 10.0 * exp + (c - '0');
		exp *= expsign;

		*x = *x * pow(10.0, exp);
	}

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
