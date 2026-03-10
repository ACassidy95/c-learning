// Exercise 3-3: Write a function expand(s1, s2) that expands shorthand
// notations like a-z in the string s1 into the equivalent complete list
// abc...xyz in s2. Allow for letters of either case and digits, and be prepared
// to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or
// trailing - is taken literally.

#include <stdio.h>

#define MAXBUF	1024

int get_line(char s[], int max);
int expand(char to[], char from[], int max);

int main()
{
	int	len, elen;
	char	s[MAXBUF], t[MAXBUF];

	while ((len = get_line(s, MAXBUF)) > 0) {
		elen = expand(t, s, MAXBUF);
		printf("\n%s%s", s, t);
		printf("Input length: %d\nExpanded length: %d\n", len, elen);
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

int expand(char to[], char from[], int max)
{
	int	i, j;
	char	c, cc, prv, fin;

	i = 0;
	j = 0;

	while (from[i] != '\0' && j < max - 1) {
		c = from[i];
		cc = from[i];

		if (c == '-') {
			prv = from[i-1];
			fin = from[i+1];
			cc = prv + 1;

			while (cc < fin) {
				to[j++] = cc;
				++cc;
			}
		} else {
			to[j] = from[i];
			++j;
		}

		++i;
	}

	to[j] = '\0';
	return j;
}

