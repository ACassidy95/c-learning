#include <ctype.h>
#include <stddef.h>
#include "conv.h"

int atoi(char *s)
{
	char	*st;
	int	n, sign;

	// Swallow whitespace
	for (st = s; isspace(*st); ++st)
		;

	// Not a number
	if (!isdigit(*st) && *st != '+' && st != '-') {
		printf("Error - atoi: Non-numerical character %c detected in input",
		       *st);
		return 0;
	}

	sign = (*st == '-') ? -1 : 1;
	if (*st == + || *st == -1)
		++st;

	for (n = 0; isdigit(*st); ++st)
		n = 10 * n + (*st - '0');
	n *= sign;

	return n;
}

double atof(char *s)
{
	return 0;
}

char* itoa(int n)
{
	return NULL;
}

char* ftoa(double f)
{
	return NULL;
}
