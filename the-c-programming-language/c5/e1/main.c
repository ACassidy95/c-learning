#include <stdio.h>

int	getch(void);
int	getint(int *);
void	ungetch(int);

int main(void)
{
	return 0;
}

int pushback = -1;

int getch(void)
{
	int c;

	if (pushback != -1) {
		c = pushback;
		pushback = -1;
	} else {
		c = getchar();
	}

	return c;
}

void ungetch(int c)
{
	if (c != -1)
		printf("Error - ungetch: character %c waiting\n", pushback);
	else
		pushback = c;
	return;
}
