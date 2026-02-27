// Exercise 1-8: Write a program to count blanks, tabs, and newlines

#include <stdio.h>

int main()
{
	int c;
	int nb, nt, nn;

	nb = 0;
	nt = 0;
	nn = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nn;
	}

	printf("%6c %6c %6c\n", 'B', 'T', 'N');
	printf("%6d %6d %6d\n", nb, nt, nn);
}

