#ifndef __STR_H
#define __STR_H

#include <stddef.h>

size_t	str_cat(char *, char*);
size_t	str_len(char *);
int	str_ncmp(char *, char *, size_t n);
size_t	str_ncpy(char *, char *, size_t n);
void	str_rev(char *);

#endif
