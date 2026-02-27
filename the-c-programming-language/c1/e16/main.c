// Exercise 1-16: Revise the main routine of the longest-line program so it will
// correctly print the length of arbitrarily long input lines and as much as
// possible of the text

#include <stdio.h>

#define MAXLINE 1024

int get_line(char line[], int maxline);

int main()
{
	int	len;
	int	max;
	char	line[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		printf("%5d - %s\n", len, line);
	}

	return 0;
}

int get_line(char line[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline && ((c = getchar()) != EOF) && c!= '\n'; ++i) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}
