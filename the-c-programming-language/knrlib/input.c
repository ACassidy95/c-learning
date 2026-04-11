#include <stddef.h>
#include <stdio.h>
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

void ungetch(int c)
{
	if (pb != -1)
		printf("Error - ungetch: Push back failed %c waiting\n", pb);
	else
		pb = c;
	return;
}

