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
	int i, j;

	i = 0;
	j = 0;
	while (from[i] != '\0' && j < max - 1) {
		switch (from[i]) {
		case '\n':
			to[j++] = '\\';
			to[j++] = 'n';
		case '\t':
			to[j++] = '\\';
			to[j++] = 't';
		default:
			to[j] = from[i];
		}

		++i;
		++j;
	}

	to[j] = '\0';
	return j;
}
