// Exercise 1-20: Write a program that replaces tabs in its input with the
// proper number of blanks to space to the next tab stop. Assume a fixed set of
// tab stops, every n columns

#include <stdio.h>

#define MAXLINE	1024
#define	TABSTOP	8

int get_line(char line[], int maxline);
int detab(char to[], char from[]);

int main()
{
	int	len, dlen;
	char	line[MAXLINE];
	char	dline[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		printf("%5d - %s", len, line);
		dlen = detab(dline, line);
		printf("%5d - %s", dlen, dline);
	}

	return 0;
}

int get_line(char line[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}

int detab(char to[], char from[])
{
	int i, j;

	i = 0;
	j = 0;

	while (from[i] != '\n' && i < MAXLINE - 1) {
		if (from[i] == '\t') {
			to[j] = ' ';
			++j;

			while (j % TABSTOP != 0) {
				to[j] = ' ';
				++j;
			}
		} else {
			to[j] = from[i];
			++j;
		}

		++i;
	}

	if (from[i] == '\n') {
		to[j] = '\n';
		++j;
	}

	to[j] = '\0';
	return j;
}
