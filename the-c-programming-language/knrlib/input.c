#include "input.h"

/* Pushback character for getch/ungetch*/
static int pb = -1;

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
