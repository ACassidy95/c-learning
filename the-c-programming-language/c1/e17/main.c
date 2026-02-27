// Exercise 1-17: Write a program to print all input lines longer than 80
// characters

#include <stdio.h>

#define MAXLINE	1024
#define MINLEN	80

int get_line(char line[], int maxline);

int main()
{
	int	len;
	char	line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > MINLEN)
			printf("%5d- %s", len, line);
	}

	return 0;
}

int get_line(char line[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline && ((c = getchar()) != EOF) && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}
