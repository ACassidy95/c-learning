#include <ctype.h>
#include <stdio.h>

#define MAXLINE 1024

int	get_line(char s[], int lim);
double	atof(char s[]);
double	pow(double base, double exp);
double	dabs(double x);

int main()
{
	double	d, sum;
	char	line[MAXLINE];

	sum = 0;
	while (get_line(line, MAXLINE) > 0) {
		d = atof(line);
		printf("%lf: %lf + %lf = %lf\n", d, sum, d, sum + d);
		sum += d;
	}

	return 0;
}

int get_line(char s[], int lim)
{
	int	i;
	char	c;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

double atof(char s[])
{
	double	f, val, power, exp, exppow;
	int	i, sign, expsign, scinot;

	for(i = 0; isspace(s[i]); ++i)
		;

	scinot = -1;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		++i;

	for (val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		++i;
	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	f = sign * val / power;

	if (s[i] == 'e' || s[i] == 'E') {
		++i;
		scinot = 1;
	}

	expsign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		++i;

	for (exp = 0.0; isdigit(s[i]); ++i)
		exp = 10.0 * exp + (s[i] - '0');

	if (scinot) {
		f *= pow(10.0, expsign * exp);
	}

	return f;
}

double pow(double base, double exp)
{
	double	p, a;
	int	i;

	p = 1.0;
	a = dabs(exp);
	for (i = 0; i < a; ++i) {
		if (exp < 0)
			p /= base;
		else
			p *= base;
	}

	return p;
}

double dabs(double x)
{
	double xx;

	if (x >= 0)
		xx = x;
	else
		xx = x * -1.0;

	return xx;
}
