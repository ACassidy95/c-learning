// Exercise 3-2: Write a function escape(s, t) that converts characters like
// newline and tab into their representations \n, \t, etc. as it copies the
// string t to s. Use a switch. Write a function for the other direction also,
// i.e. convert escape representations into the real characters.

#include <stdio.h>

#define MAXBUF	1024

int get_line(char s[], int max);
int copy_collapse(char to[], char from[], int max);
int copy_expand(char to[], char from[], int max);

int main()
{
	int	i, j, k;
	char	s[MAXBUF], t[MAXBUF], u[MAXBUF];

	i = 0;
	j = 0;
	k = 0;

	while ((i = get_line(s, MAXBUF)) > 0) {
		j = copy_collapse(t, s, MAXBUF);
		k = copy_expand(u, s, MAXBUF);

		printf("%s\n%s\n", t, u);
		printf("Original length: %3d\n", i);
		printf("Collapsed escape length: %3d\n", j);
		printf("Expanded literal length: %3d\n\n", k);
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

int copy_collapse(char to[], char from[], int max)
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

int copy_expand(char to[], char from[], int max)
{
	int	i, j;
	char	c;

	i = 0;
	j = 0;

	while (from[i] != '\0' && j < max - 1) {
		c = from[i];
		switch (c) {
		case '\\':
			switch (from[i+1]) {
			case 'n':
				to[j] = '\n';
				++i;
				break;
			case 't':
				to[j] = '\t';
				++i;
				break;
			default:
				to[j] = from[i];
			}
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
