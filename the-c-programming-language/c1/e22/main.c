// Exercise 1-22: Write a program to fold long input lines into two or more
// shorter lines after the last non-blank character that occurs before the n-th
// column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the n-th column.

#include <stdio.h>

#define MAXLINE		1024
#define MAXWIDTH	30

int get_line(char line[], int maxline);
void fold_line(char folded[], char line[], int maxwidth);

int main()
{
	int	len, i;
	char	line[MAXLINE], fline[MAXLINE];

	i = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		if (len > MAXWIDTH) {
			fold_line(fline, line, MAXWIDTH);
			printf("%s", fline);
		} else {
			printf("%s", line);
		}
		printf("\n");
		++i;
	}

	return 0;
}

int get_line(char line[], int maxline) {
	int c, i;

	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';
	return i;
}

void fold_line(char folded[], char line[], int maxwidth) {
	int i, j;
	int bpos;

	i = 0;
	j = 0;
	bpos = -1;
	while (line[i] != '\0') {
		folded[i] = line[i];

		if (line[i] == ' ' || line[i] == '\t')
			bpos = i;

		if (j > 0 && j % maxwidth == 0) {
			folded[bpos] = '\n';
			j = i - bpos;
		} else {
			++j;
		}

		++i;
	}

	folded[i] = '\0';
}
