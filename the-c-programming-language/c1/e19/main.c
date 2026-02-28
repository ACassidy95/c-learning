// Exercise 1-19: Write a function reverse(s) that reverses the character string
// s. Use it to write a program that reverses its input one line at a time

#include <stdio.h>

#define MAXLINE 1024

int get_line(char line[], int maxline);
void reverse_line(char line[]);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = get_line(line, MAXLINE)) > 0) {
		printf("\t%s\n", line);
		reverse_line(line);
		printf("\t%s\n", line);
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

void reverse_line(char line[])
{
	int i, j;
	char c[MAXLINE];

	i = 0;
	while (line[i] != '\n') {
		c[i] = line[i];
		++i;
	}

	j = 0;
	while(i > 0) {
		line[j] = c[i - 1];
		--i;
		++j;
	}

	line[j] = '\n';
	++j;
	line[j] = '\0';
	j = 0;
}

