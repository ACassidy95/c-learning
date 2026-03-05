// Exercise 1-22: Write a program to fold long input lines into two or more
// shorter lines after the last non-blank character that occurs before the n-th
// column of input. Make sure your program does something intelligent with very
// long lines, and if there are no blanks or tabs before the n-th column.

#include <stdio.h>

#define MAXLINE		1024
#define MAXWIDTH	20

int get_line(char line[], int maxline);
void fold_line(char folded[], char line[], int maxwidth);

int main()
{
	int	len, i;
	char	line[MAXLINE], fline[MAXLINE];

	i = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {
		fold_line(fline, line, MAXWIDTH);
		printf("%s", fline);
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
	int i, j, diff;
	int bpos, col;

	i	= 0;
	j	= 0;
	diff	= 0;
	col	= 0;
	bpos	= -1;
	while (line[i] != '\0') {
		if (line[i] == ' ' || line[i] == '\t')
			bpos = i;

		if (col > 0 && col % maxwidth == 0) {
			// If no blank has been seen since the last break was
			// inserted, insert a hyphen and newline at the
			// subsequent j (folded line) index
			if (i - col >= bpos) {
				folded[j] = '-';
				++j;
				folded[j] = '\n';
				++j;

				col = 1;
				diff = j - i;
			} else {
				folded[bpos + diff] = '\n';
				col = i - bpos;
			}
		} else {
			++col;
		}

		folded[j] = line[i];
		++j;
		++i;
	}

	folded[j] = '\0';
}
