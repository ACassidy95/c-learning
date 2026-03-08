// Exercise 1-23: Write a program to remove all comments from a C program.
// Don't forget to handle quoted strings and character constants properly. C
// comments don't nest.

/* Trad comment */

/* Multiline
 * comment
 */

#include <stdio.h>

int main()
{
	int state, lpos;
	char c, peek; // An in-line comment

	state = 0;
	lpos = 0;
	while((c = getchar()) != EOF) {
		if (c == '/') {
			peek = getchar();

			if (peek == '*') {
				if (state == 0)
					state = 1;

				while (state == 1) {
					while ((c = getchar()) != '*')
						;
					peek = getchar();

					if (peek == '/')
						state = 0;
				}
			} else if (peek == '/') {
				while ((c = getchar()) != '\n')
					;
				if (lpos > 0) {
					putchar(c);
					++lpos;
				}
			} else {
				putchar(c);
				putchar(peek);
				lpos = lpos + 2;
			}
		} else {
			if (!(c == '\n' && lpos == 0))
				putchar(c);
			lpos++;
		}
	}
}

