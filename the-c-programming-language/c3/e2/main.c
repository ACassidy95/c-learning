// Exercise 3-2: Write a function escape(s, t) that converts characters like
// newline and tab into their representations \n, \t, etc. as it copies the
// string t to s. Use a switch. Write a function for the other direction also,
// i.e. convert escape representations into the real characters.

#include <stdio.h>

#define MAXBUF	1024

int get_line(char s[], int max);
int copy(char to[], char from[], int max);

int main()
{
	int	i, j;
	char	s[MAXBUF], t[MAXBUF];

	i = 0;
	j = 0;

	while ((i = get_line(s, MAXBUF)) > 0) {
		j = copy(t, s, MAXBUF);
		printf("%s\nOriginal length: %d\nExpanded length: %d\n\n",
		       t, i, j);
	}

	return 0;
}

int get_line(char s[], int max)
{
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
	return i;
}

int copy(char to[], char from[], int max)
{
	int	i, j;
	char	c;

	i = 0;
	j = 0;
	while (from[i] != '\0' && j < max - 1) {
		c = from[i];
		switch (c) {
		case '\n':
			to[j++] = '\\';
			to[j] = 'n';
			break;
		case '\t':
			to[j++] = '\\';
			to[j] = 't';
			break;
		default:
			to[j] = from[i];
		}

		++i;
		++j;
	}

	to[j] = '\0';
	return j;
}
