#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP		100 // Maximum width of operator/operand
#define	MAXSTACK	100 // Maximum value stack depth
#define NUMBER		'0' // Signal detection of a number in input

int	getop(char []);
void	push(double);
double	pop(void);

// Value stack and stack pointer
double	val[MAXSTACK];
int	valsp = 0;

int main()
{
	// Ensures operands of non-commutative operators are evaluated in the
	// correct order
	double	opd2;
	int	type;
	char	s[MAXOP];

	return 0;
}

void push(double f)
{
	if (valsp < MAXSTACK)
		val[valsp++] = f;
	else
		printf("Error: Stack overflow - max %d\n", MAXSTACK);

	return;
}

double pop(void)
{
	double f;

	f = 0.0;
	if (valsp > 0)
		f = val[--valsp];

	return f;
}

#define UGBUFSIZE 8

char	ugbuf[UGBUFSIZE];
int	ugbufp = 0;

int	getch(void);
void	ungetch(int);

int getop(char s[])
{
	int i, c, op;

	while (isspace(s[0] = c = getch()))
		;
	s[1] = '\0';

	// Not a number
	if (!isdigit(c) && c != '.')
		op = c;
	else if(isdigit(c)) {
		i = 0;

		// Collect integer part of input number
		while (isdigit(s[++i] = c = getch()))
			;
		if (c == '.')
			// Collect fractional part of input number
			while(isdigit(s[++i] = c = getch()))
				;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);

		op = NUMBER;
	}

	return op;
}

// Retrieve a pushed-back character or one from stdin
int getch(void)
{
	int c;

	if (ugbufp > 0)
		c = ugbuf[--ugbufp];
	else
		c = getchar();

	return c;
}

// Push an unwanted character back to input
void ungetch(int c)
{
	if (ugbufp >= UGBUFSIZE)
		printf("Error: ungetch limit of %d exceeded\n", UGBUFSIZE);
	else
		ugbuf[ugbufp++] = c;
	return;
}

