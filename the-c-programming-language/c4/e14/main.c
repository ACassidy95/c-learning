// Exercise 4-14: Define a macro swap(t, x, y) that interchanges two arguments
// of type x, y of type t

#include <stdio.h>

#define swap(t, x, y) \
{ \
	t tmp; \
	tmp = x; \
	x = y; \
	y = tmp; \
}

int main(void)
{
	int	m, n;
	double	x, y;

	m = 0;
	n = 1;
	x = 0.0;
	y = 1.0;

	printf("m = %d, n = %d, x = %.2lf, y = %.2lf\n", m, n, x, y);

	swap(int, m, n);
	swap(double, x, y);

	printf("m = %d, n = %d, x = %.2lf, y = %.2lf\n", m, n, x, y);

	return 0;
}
