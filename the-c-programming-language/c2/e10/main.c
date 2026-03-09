// Exercise 2-10: Rewrite the lower function which converts uppercase to
// lowercase letters with a conditonal instead of if-else

#include <ctype.h>
#include <stdio.h>

#define MAXBUF 1024

int get_lower(char s[], int max);

int main()
{
	int len;
	char s[MAXBUF];

	while ((len = get_lower(s, MAXBUF)) > 0) {
		printf("%s", s);
	}

	return 0;
}

int get_lower(char s[], int max)
{
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = isalpha(c) ? tolower(c) : c ;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
	return i;
}
