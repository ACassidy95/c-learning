#include <stdio.h>

#define MAXSTR	1024

int get_line(char *, int);
int str_cat(char *, char *);
int str_end(char *, char *);
int str_len(char*);

int main(void)
{
	int	sl, tl, cl;
	char	s[MAXSTR], t[MAXSTR];

	while (sl = get_line(s, MAXSTR)) {
		tl = get_line(t, MAXSTR);

		if (str_end(s, t))
			printf("\"%s\" occurs at the end of \"%s\" without concatenation\n", t, s);

		cl = str_cat(s, t);
		printf("Concat: %s\nlen(s): %d\nlen(t): %d\nlen(s#t): %d\n",
		       s, sl, tl, cl);
	}

	return 0;
}

int get_line(char *s, int lim)
{
	int c, n;

	n = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		*(s + n++) = c;
	}
	if (c == '\n') {
		*(s + n++) = c;
	}
	*(s + n) = '\0';

	return n;
}

// Concatenates the contents of s and t and stores the result in s,
// while returning the length of the combined string.
int str_cat(char *s, char *t)
{
	int i, sl;

	i = 0;
	sl = str_len(s);
	while (*t && sl + i < MAXSTR) {
		*(s + sl + i) = *t;
		++t;
		++i;
	}
	*(s + sl + i) = '\0';

	return sl + i;
}

// Determines if t occurs at the end of s. Returns 1 if so and 0 otherwise.
int str_end(char *s, char *t)
{
	int i, j, sl, tl;

	sl = str_len(s);
	tl = str_len(t);

	if (tl > sl) {
		printf("Error - str_end: Search string longer than target string %d > %d.\n", tl, sl);
		return 0;
	}

	s += sl - tl;
	for ( ; *s && *t && *s == *t; s++, t++)
		;
	if (*t)
		return 0;
	return 1;
}

int str_len(char *s)
{
	int i;

	i = 0;
	while (*s) {
		++s;
		++i;
	}

	return i;
}
