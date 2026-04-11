#ifndef __INPUT_H
#define __INPUT_H

#include <stddef.h>

#define MAXLINE 1024

/* Reads from stdin up to '\n' or the provided limit is reached and returns the
 * number of characters read. */
size_t get_line(char *, size_t);

#endif
