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
	// Flag if inside a multiline comment
	int	ml_cmt;

	// c - current input character
	// peek - inspect next input character
	// discard - unneeded input characters
	char	c, peek, discard;

	ml_cmt = 0;
	while((c = getchar()) != EOF) {
		if (c == '/') {
			peek = getchar();

			if (peek == '*') {
				if (ml_cmt == 0)
					ml_cmt = 1;

				while (ml_cmt == 1) {
					while ((discard = getchar()) != '*')
						;
					peek = getchar();

					if (peek == '/')
						ml_cmt = 0;
				}
			} else if (peek == '/') {
				while ((discard = getchar()) != '\n')
					;
			} else {
				putchar(c);
				putchar(peek);
			}
		} else {
				putchar(c);
		}
	}
}

