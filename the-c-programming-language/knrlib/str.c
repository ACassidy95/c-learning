#include "str.h"

/* Writes the contents of src to the end of the contents of dst. If space in the
 * dst buffer runs out, as much as possible will be concatenated. Returns the
 * length of the concatenation. */
size_t str_cat(char *dst, char *src)
{
	return 0;
}

/* Returns the length of s minus the null-terminator */
size_t str_len(char *s)
{
	return 0;
}

/* Compares the first n bytes of s, t. Returns 0 if s == t, -1 if s < t,
 * or 1 if s > t in lexicographical order. */
int str_ncmp(char *s, char *t, size_t n)
{
	return 0;
}

/* Copies the first n bytes of src to the first n bytes of dst. If fewer than n
 * bytes of space are available in dst, as much as possible of src will be
 * written. Returns the number of bytes written. */
size_t str_ncpy(char *dst, char *src, size_t n)
{
	return 0;
}

/* Reverses s in place. */
void str_rev(char *s)
{
	return;
}
