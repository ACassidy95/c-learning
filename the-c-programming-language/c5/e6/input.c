#include <stdio.h>
#include "input.h"

size_t get_line(char *s, size_t max)
{
	char	*st;
	int	c;
	size_t	n;

	st = s;
	n = 0;
	while (--max > 0 && (c = getchar()) != EOF && c != '\n') {
		*st++ = c;
		++n;
	}
	if (c == '\n') {
		*st++ = '\n';
		++n;
	}
	*st = '\0';

	return n;
}
