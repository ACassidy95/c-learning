// Exercise 1-23: Write a program to remove all comments from a C program.
// Don't forget to handle quoted strings and character constants properly. C
// comments don't nest.

/* Trad comment */

/* Multiline
 * comment
 */

#include <stdio.h>

#define MAXLINE	1024

int main()
{
	int incmt, lpos;
	char c, lka; // An in-line comment

	incmt = 0;
	lpos = 0;
	while((c = getchar()) != EOF) {
		if (c == '/') {
			lka = getchar();

			if (lka == '*') {
				if (incmt == 0)
					incmt = 1;

				while (incmt == 1) {
					while ((c = getchar()) != '*')
						;
					lka = getchar();

					if (lka == '/')
						incmt = 0;
				}
			} else if (lka == '/') {
				while ((c = getchar()) != '\n')
					;
				if (lpos > 0) {
					putchar(c);
					++lpos;
				}
			} else {
				putchar(c);
				putchar(lka);
				lpos = lpos + 2;
			}
		} else {
			if (!(c == '\n' && lpos == 0))
				putchar(c);
			lpos++;
		}
	}
}

