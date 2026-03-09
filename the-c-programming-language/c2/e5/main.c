// Exercise 2-5: Write a function any(s1, s2) which returns the first location
// in s1 where any character in s2 occurs, or -1 if s1 contains no characters
// from s2.

#include <stdio.h>

#define MAXLINE 1024

int get_line(char s[], int max);
int any(char s1[], char s2[]);

int main()
{
	int l1, l2, found, i;
	char s1[MAXLINE], s2[MAXLINE];

	l1 = get_line(s1, MAXLINE);
	l2 = get_line(s2, MAXLINE);
	while ( l1 > 0 && l2 > 0) {
		found = any(s1, s2);

		if (found == -1) {
			printf("No overlap in input strings\n");
		} else {
			printf("First overlap at index %d of: ", found);
			for (i = 0; s1[i] != '\0'; ++i) {
				if (i == found)
					printf("[%c]", s1[i]);
				else
					printf("%c", s1[i]);
			}
			printf("\n");
		}

		l1 = get_line(s1, MAXLINE);
		l2 = get_line(s2, MAXLINE);
	}

	return 0;
}

int get_line(char s[], int max)
{
	int c, i;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	// Swallow newlines from input as they are trivial for purposes of this
	// program
	s[i] = '\0';
	return i;
}

int any(char s[], char t[])
{
	int i, j, found;

	found = -1;
	for (i = 0; found == -1 && s[i] != '\0'; ++i)
		for (j = 0; found == -1 && t[j] != '\0'; ++j)
			if (s[i] == t[j])
				found = i;

	return found;
}
