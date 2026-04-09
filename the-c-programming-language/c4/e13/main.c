// Exercise 4-13: Write a recursive version of the function reverse(s), which
// reverses the string s in place.

#include <stdio.h>
#include <string.h>

#define MAXLINE 1024

int get_line(char [], int);
void reverse(char [], int);

int main(void)
{
	int	len;
	char	line[MAXLINE];

	while((len = get_line(line, MAXLINE))) {
		reverse(line, len);
		printf("%s\n", line);
	}

	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = '\n';
	s[i] = '\0';

	return i;
}

void reverse(char s[], int len)
{
	int st, e, t;

	st = 0;
	e = len - 1;

	if (st < e) {
		t = s[st];
		s[st] = s[e];
		s[e] = t;

		reverse(s + 1, e - 1);
	}

	return;
}
