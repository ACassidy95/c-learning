#include <ctype.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include "conv.h"

int atoi(char *s)
{
	char	*st;
	int	n, sign;

	// Swallow whitespace
	for (st = s; isspace(*st); ++st)
		;

	// Not a number
	if (!isdigit(*st) && *st != '+' && *st != '-') {
		printf("Error - atoi: Non-numerical character %c detected in input\n",
		       *st);
		return 0;
	}

	sign = (*st == '-') ? -1 : 1;
	if (*st == '+' || *st == '-') {
		++st;
		while (!isdigit(*st))
			++st;
	}

	for (n = 0; isdigit(*st); ++st)
		n = 10 * n + (*st - '0');
	n *= sign;

	return n;
}

double atof(char *s)
{
	return 0;
}

int itoa(int n, char *s)
{
	int	l, nc, mag;
	char	*st;

	st = s;
	if ((nc = n) < 0) {
		if (n == INT_MIN)
			n = -n - 1;
		else
			n = -n;
	}

	l = 0;
	if (nc < 0) {
		*st++ = '-';
		++l;
	}

	mag = 1;
	do {
		mag *= 10;
	} while (nc /= 10);
	mag /= 10;

	for (; mag; mag /= 10) {
		*st++ = '0' + (n / mag) % 10;
		++l;
	}
	*st = '\0';

	return l;
}

int ftoa(double f, char *s)
{
	return 0;
}
