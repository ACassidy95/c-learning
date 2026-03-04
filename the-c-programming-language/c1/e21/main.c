// Exercise 1-21: Write a program entab that replaces strings of blanks by the
// minimum number of tabs and blanks to achieve the same spacing

#include <stdio.h>

#define MAXLINE	1024
#define TABSTOP	8

int get_line(char line[], int maxline);
int entab(char to[], char from[]);

int main()
{
	int	len, elen;
	char	line[MAXLINE];
	char	eline[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		printf("%5d - %s", len, line);
		elen = entab(eline, line);
		printf("%5d - %s", elen, eline);
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

int entab(char to[], char from[])
{
	int i, j, k;
	int tbs, blks;

	i = 0;
	j = 0;

	while (j < MAXLINE - 1 && from[i] != '\n') {
		if (from[i] == ' ') {
			k	= i;
			tbs	= 0;
			blks	= 0;

			while (from[k] == ' ') {
				++k;
				++blks;
				if (k % TABSTOP == 0) {
					tbs++;
					blks = 0;
				}
			}

			while (tbs > 0) {
				to[j] = '\t';
				++j;
				--tbs;
			}

			while (blks > 0) {
				to[j] = ' ';
				++j;
				--blks;
			}

			i = k;
		} else {
			to[j] = from[i];
			++i;
			++j;
		}
	}

	if (from[i] == '\n') {
		to[j] = '\n';
		++j;
	}

	to[j] = '\0';
	return j;
}
