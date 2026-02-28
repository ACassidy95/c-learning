// Exercise 1-18: Write a program to remove trailing blanks and tabs from each
// line of input, and to delete entirely blank lines.

#include <stdio.h>

#define MAXLINE 1024

int get_line(char line[], int maxline);
int prune_line(char line[], int len);
void swap(char line[], int i, int j);

int main()
{
	int	len, plen;
	char	line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		printf("Input: %5d- %s", len, line);
		plen = prune_line(line, len);
		printf("Prune: %5d- %s\n", plen, line);
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

int prune_line(char line[], int len)
{
	int i, j;

	i = 0;
	j = 0;
	while (line[i] != '\0') {
		if (line[i] == ' ' || line[i] == '\t') {
			while (line[j] == ' ' || line[j] == '\t')
				++j;

			if (line[j] != '\n' && line[j] != '\0')
				i = j;
			else
				swap(line, i, j);

		} else {
			++i;
			++j;
		}
	}

	return i;
}

void swap(char line[], int i, int j)
{
	char c;

	c = line[i];
	line[i] = line[j];
	line[j] = c;
}
