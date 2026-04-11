#include <stddef.h>
#include <stdio.h>

#define MAXSTR	1024

int	get_line(char *, size_t);
size_t	str_cat(char *, char *);
size_t	str_ncat(char *, char*, size_t);
int	str_end(char *, char *);
size_t	str_len(char*);
int	str_ncmp(char *, char *, size_t);
int	str_ncpy(char *, char *, size_t);

char *st1 = "Test string 1";
char *st2 = "Test string 2";
char *st3 = "Test string 1";
char *st4 = "Copy Me!";

int main(void)
{
	size_t	sl, tl, cl, cnl;
	char	s[MAXSTR], t[MAXSTR];

	while (sl = get_line(s, MAXSTR)) {
		tl = get_line(t, MAXSTR);

		if (str_end(s, t))
			printf("End: String 2 found as suffix in String 1\n");

		cl = str_cat(s, t);
		printf("Cat:\nlen(s): %d\nlen(t): %d\nlen(s#t): %d\n",
		       sl, tl, cl);

		cnl = str_ncat(s, t, 5);
		printf("Ncat:\nlen(s): %d\nlen(t): %d\nlen(s#5t): %d\n",
		       sl, tl, cnl);

		printf("Ncmp:\ncmp(%s, %s, 5): %d\ncmp(%s, %s, 13): %d\ncmp(%s, %s, 13): %d\n"
		       "cmp(%s, %s, 20): %d\ncmp(%s, %s, 5): %d\ncmp(%s, %s, 13): %d\n"
		       "cmp(%s, %s, 20): %d\n",
		       st1, st2, str_ncmp(st1, st2, 5),
		       st1, st2, str_ncmp(st1, st2, 13),
		       st2, st1, str_ncmp(st2, st1, 13),
		       st1, st2, str_ncmp(st1, st2, 20),
		       st1, st3, str_ncmp(st1, st3, 5),
		       st1, st3, str_ncmp(st1, st3, 13),
		       st1, st3, str_ncmp(st1, st3, 20));

		printf("Ncpy:\nncpy(%s, %s, 5): %d\n",
		       s, t, str_ncpy(s, t, 5));
	}

	return 0;
}

int get_line(char *s, size_t lim)
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
size_t str_cat(char *s, char *t)
{
	size_t i, sl;

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

// Concatenates n bytes of t to the end of s and returns the combined length
size_t str_ncat(char *s, char *t, size_t n)
{
	size_t i, sl;

	i = 0;
	sl = str_len(s);

	while (*t && sl + i < MAXSTR && n > 0) {
		*(s + sl + i) = *t;
		++t;
		++i;
		--n;
	}
	*(s + sl + i) = '\0';

	return sl + i;
}

// Copies the first n bytes of t (or as many as available/possible) into first n
// bytes of s. Returns 0 if all bytes copied. Returns >0 if fewer than n bytes
// copied for whatever reason with value being count of leftover bytes, i.e.
// fewer than n bytes in t, or space restrictions in s.
int str_ncpy(char *s, char *t, size_t n)
{
	while (*s && *t && n > 0) {
		*s++ = *t++;
		--n;
	}

	return n;
}

// Determines if t occurs at the end of s. Returns 1 if so and 0 otherwise.
int str_end(char *s, char *t)
{
	size_t sl, tl;

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

// Compares the first n elements of two strings s and t.
// Returns -1 if s<t, 0 if s==t, and 1 if s>t.
int str_ncmp(char *s, char *t, size_t n)
{
	int cmp;

	cmp = 0;
	for (; *s && *t && n > 0 && *s == *t; s++, t++, n--)
		;
	if (n) {
		if (*s < *t)
			cmp = -1;
		else if (*s > *t)
			cmp = 1;
	}

	return cmp;
}

size_t str_len(char *s)
{
	size_t i;

	i = 0;
	while (*s) {
		++s;
		++i;
	}

	return i;
}
