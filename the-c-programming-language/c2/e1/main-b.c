// Exercise 2-1b: Write a program to determine the ranges of char, short, int,
// and long variables, both signed and unsigned by printing appropriate values
// from direct calculation.

#include <limits.h>
#include <stdio.h>

#define LIM_MIN	0
#define LIM_MAX	1

unsigned char	calculate_unsigned_char_max();
signed char	calculate_signed_char_limit(int lim, unsigned char ucmax);
unsigned short	calculate_unsigned_short_max();
signed short	calculate_signed_short_limit(int lim, unsigned short usmax);
unsigned int	calculate_unsigned_int_max();
signed int	calculate_signed_int_limit(int lim, unsigned int uimax);
unsigned long	calculate_unsigned_long_max();
signed long	calculate_signed_long_limit(int lim, unsigned long ulmax);

int main()
{
	unsigned char	ucmax, hucmax;
	signed char	scmin, scmax, hscmin, hscmax;

	unsigned short	usmax, husmax;
	signed short	ssmin, ssmax, hssmin, hssmax;

	unsigned int	uimax, huimax;
	signed int	simin, simax, hsimin, hsimax;

	unsigned long	ulmax, hulmax;
	signed long	slmin, slmax, hslmin, hslmax;

	hucmax = UCHAR_MAX;
	ucmax = calculate_unsigned_char_max();

	if (ucmax == hucmax)
		printf("Unsigned char max: %+5u\n", ucmax);

	hscmin = SCHAR_MIN;
	hscmax = SCHAR_MAX;
	scmin = calculate_signed_char_limit(LIM_MIN, ucmax);
	scmax = calculate_signed_char_limit(LIM_MAX, ucmax);

	if (scmin == hscmin && scmax == hscmax) {
		printf("Signed char min: %+5d\n", scmin);
		printf("Signed char max: %+5d\n", scmax);
	}

	husmax = USHRT_MAX;
	usmax = calculate_signed_short_max();

	if (usmax == husmax)
		printf("Unsigned short max: %+5u\n", usmax);

	hssmin = SHRT_MIN;
	hssmax = SHRT_MAX;
	ssmin = calculate_signed_short_limit(LIM_MIN, usmax);
	ssmax = calculate_signed_short_limit(LIM_MAX, usmax);

	return 0;
}

unsigned char calculate_unsigned_char_max()
{
	unsigned char uc, ucn;

	uc = 0;
	ucn = uc + 1;
	while (uc < ucn) {
		++uc;
		++ucn;
	}

	return uc;
}

unsigned short calculate_unsigned_short_max()
{
	unsigned short us, usn;

	us = 0;
	usn = us + 1;
	while (us < usn) {
		++us;
		++usn;
	}

	return us;
}

unsigned int calculate_unsigned_int_max()
{
	unsigned int ui, uin;

	ui = 0;
	uin = ui + 1;
	while (ui < uin) {
		++ui;
		++uin;
	}

	return ui;
}

unsigned long calculate_unsigned_long_max()
{
	unsigned long ul, uln;

	ul = 0;
	uln = ul + 1;
	while (ul < uln) {
		++ul;
		++uln;
	}

	return ul;
}

signed char calculate_signed_char_limit(int limit, unsigned char ucmax)
{
	signed char sclim;

	sclim = ucmax / 2;
	if (limit == LIM_MIN)
		sclim = (sclim * -1) - 1;

	return sclim;
}

signed short calculate_signed_short_limit(int limit, unsigned short usmax)
{
	signed short sslim;

	sslim = usmax / 2;
	if (limit == LIM_MIN)
		sslim = (sslim * -1) - 1;

	return sslim;
}

signed int calculate_signed_int_limit(int limit, unsigned int uimax)
{
	signed int silim;

	silim = uimax / 2;
	if (limit == LIM_MIN)
		silim = (silim * -1) - 1;

	return silim;
}

signed long calculate_signed_long_limit(int limit, unsigned long ulmax)
{
	signed long sllim;

	sllim = ulmax / 2;
	if (limit == LIM_MIN)
		sllim = (sllim * -1) - 1;

	return sllim;
}
