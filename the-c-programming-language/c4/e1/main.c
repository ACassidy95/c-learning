#include <stdio.h>

#define MAXLINE 1024

int get_line(char line[], int lim);
int strlindex(char str[], char find[]);
int strrindex(char str[], char find[]);

char pattern[] = "ould";

int main()
{
	int	lidx, ridx;
	char	line[MAXLINE];

	while (get_line(line, MAXLINE) > 0) {
		if ((lidx = strlindex(line, pattern)) >= 0 &&
		    (ridx = strrindex(line, pattern)) >= 0) {
			printf("%s\t- l: %d, r: %d\n", line, lidx, ridx);
		}
	}

	return 0;
}

int get_line(char line[], int lim)
{
	int	i;
	char	c;

	i = 0;
	while (lim-- > 0 && (c = getchar()) != EOF && c != '\n')
		line[i++] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';

	return i;
}

int strlindex(char str[], char find[])
{
	return 0;
}

int strrindex(char str[], char find[])
{
	return 0;
}
