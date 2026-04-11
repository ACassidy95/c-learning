#ifndef __INPUT_H
#define __INPUT_H

#include <stddef.h>

/* Read character pushed back from ungetch() if one exists,
 * otherwise read character from stdin */
int	getch(void);

/* Return character to be re-read by getch */
void	ungetch(int);

/* Read from stdin until \n encountered or max size reached and return line
 * length (excluding null terminator). */
size_t	getln(char *, size_t);

#endif
