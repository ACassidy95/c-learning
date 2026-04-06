#include <stdio.h>

#define MAXLINE 1024

int	get_line(char s[], int lim);
double	atof(char s[]);

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
