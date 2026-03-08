// Exercise 2-4: Write a function squeeze(s1, s2) that deletes each character
// in s1 that matches any character in s2

#include <stdio.h>

#define MAXLINE 1024

int get_line(char s[], int maxline);
void squeeze(char s[], char t[]);

int main()
{
	int l1, l2;
	char s1[MAXLINE], s2[MAXLINE];

	while ((l1 = get_line(s1, MAXLINE)) > 0 &&
	       (l2 = get_line(s2, MAXLINE)) > 0) {
		printf("Squeeze of '%s' and '%s': ", s1, s2);
		squeeze(s1, s2);
		printf("%s\n", s1);
	}

	return 0;
}

int get_line(char s[], int maxline)
{
	int c, i;

	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
	return i;
}
