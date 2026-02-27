// Exercise 1-18: Write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.

#include <stdio.h>

#define MAXLINE 1024

int get_line(char line[], int maxline);
int prune_line(char to[], char from[], int fromlen);

int main()
{
	int	len, plen;
	char	line[MAXLINE];
	char	pline[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		//plen = prune_line(pline, line, len);
		//printf("%5d- %s\n%5d- %s\n", len, line, plen, pline);
		printf("%5d- %s", len, line);
		plen = prune_line(pline, line, len);
		printf("%5d- %s\n", plen, pline);
	}

	return 0;
}

int get_line(char line[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}

int prune_line(char to[], char from[], int fromlen)
{
	int i, j;

	i = 0;
	j = 0;
	while (from[j] != '\0') {
		if (from[j] != ' ' && from[j] != '\t') {
			to[i] = from[j];
			++i;
			++j;
		} else {
			int k = j;
			while (from[k] == ' ' && from[k] == '\t')
				++k;

			if (from[k] == '\n')
				j = k;
		}
	}

	to[i] = '\0';

	return i;
}
