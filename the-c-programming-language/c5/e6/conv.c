#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "conv.h"

int atoi(char *s)
{
	char	*st;
	int	n, sign;

	/* Swallow whitespace */
	for (st = s; isspace(*st); ++st)
		;

	/* Not a numerical element. This also gates for decimal points and
	 * scientific notation marks useful for calls to this function by atof.
	 * For true integers they are simply ignored. */
	if (!isdigit(*st)
	    && *st != '+' && *st != '-'
	    && *st != '.'
	    && *st != 'e' && *st != 'E') {
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
	char	*st;
	double	f, ip, fp;
	int	esign, vsign, ep;

	st = s;
	f = ip = fp = 0.0;
	ep = 0;

	/* Obtain integer part */
	ip = atoi(st);
	f += ip;

	vsign = 1;
	if (ip < 0) {
		st++;
		vsign = -1;
	}
	while (isspace(*st))
		st++;

	do {
		st++;
	} while ((int)(ip /= 10));


	/* Obtain optional decimal part if one exists */
	if (*st == '.') {
		while (!isdigit(*++st) && *st != 'e' && *st != 'E')
			;

		fp = atoi(st);

		while((int)fp) {
			fp /= 10.0;
			st++;
		}

		if (vsign < 0)
			fp *= vsign;
		f += fp;

		while (*st == '0')
			st++;
	}

	/* Obtain optional scientific notation integer exponent part if one
	 * exists */
	if (*st == 'e' || *st == 'E') {
		while (!isdigit(*++st) && *st != '-')
			;

		ep = atoi(st);
		f *= pow(10.0, ep);
	}

	return f;
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
