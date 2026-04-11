#ifndef __CONV_H
#define __CONV_H

/* Converts a given string to integer/floating-point values.
 * Return 0 if bad input received. */
int	atoi(char *);
double	atof(char *);

/* Converts a given integer/floating-point value to string, writing to the
 * provided char * argument. Returns the length of the string on success or 0
 * on failure. */
int	itoa(int, char*);
int	ftoa(double, char*);

#endif
