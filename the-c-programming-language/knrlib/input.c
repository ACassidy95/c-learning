#include <stddef.h>
#include <stdio.h>
#include "input.h"

/* Pushback character for getch/ungetch*/
static int pb = -1;

/* Read character pushed back by ungetch() if one exists,
 * otherwise read a character from stdin. */
int getch(void)
{
	int c;

	if (pb != -1) {
		c = pb;
		pb = -1;
	} else {
		c = getchar();
	}

	return c;
}

/* Return character to be re-read by getch. */
void ungetch(int c)
{
	if (pb != -1)
		printf("Error - ungetch: Push back failed %c waiting\n", pb);
	else
		pb = c;
	return;
}

/* Read from stdin until \n encountered or max size reached and return line
 * length (excluding null terminator). */
size_t getln(char *s, size_t max)
{
	size_t l;

	for (l = 0; max > 0 && (c = getch()) != EOF && c != '\n'; ++l, --max)
		*s++ = c;
	if (c == '\n') {
		*s++ = c;
		++l;
	}
	*s = '\0';

	return l;
}

