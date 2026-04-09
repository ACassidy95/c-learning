#include <stdio.h>

#define MAXSTR	1024

int get_line(char *, int);
int str_cat(char *, char *);
int str_len(char*);

int main(void)
{
	int	sl, tl, cl;
	char	s[MAXSTR], t[MAXSTR];

	while (sl = get_line(s, MAXSTR)) {
		tl = get_line(t, MAXSTR);
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

int str_cat(char *s, char *t)
{
	int i, sl;

	i = 0;
	sl = str_len(s);
	while (*t) {
		*(s + sl + i) = *t;
		++t;
		++i;
	}
	*(s + sl + i) = '\0';

	return sl + i;
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
