#include <stdio.h>
#include "input.h"
#include "conv.h"

int main(void)
{
	char	s[MAXLINE], t[MAXLINE], u[MAXLINE];
	double	dx, dy;
	int	x, y;
	size_t  n;

	printf("> ");
	while ((n = get_line(s, MAXLINE))) {
		printf("get_line: %d - %s", n, s);

		x = atoi(s);
		printf("atoi: %d - %s", x, s);

		y = itoa(x, t);
		if (y >= 0)
			printf("itoa: %d - %s\n", x, t);

		dx = atof(s);
		printf("atof: %.3lf - %s", dx, s);

		dy = ftoa(dx, u);
		if (dy >= 0)
			printf("ftoa: %.3lf - %s\n", dy, u);

		printf("> ");
	}

	return 0;
}

