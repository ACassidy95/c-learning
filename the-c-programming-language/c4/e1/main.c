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
	int i, j, k;
	int found;

	found = -1;

	for (i = 0; str[i] != '\0'; ++i) {
		for (j = i, k = 0; find[k] != '\0' && str[j] == find[k]; ++j, ++k)
			;

		if (k > 0 && t[k] == '\0')
			found = i;
	}

	return found;
}

int strrindex(char str[], char find[])
{
	return 0;
}
