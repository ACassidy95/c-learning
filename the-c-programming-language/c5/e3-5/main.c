#include <stdio.h>

#define MAXSTR	1024

int getline(char *, int);
int strcat(char *, char *);

int main(void)
{
	return 0;
}

int getline(char *s, int lim)
{
	int c, n;

	n = 0;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		(s + n++) = c;
	if (c == '\n')
		(s + n++) = c;
	(s + n) = '\0';

	return n;
}

int strcat(char *s, char *t)
{
	return 0;
}
