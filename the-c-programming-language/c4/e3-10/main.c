#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP		100 // Maximum width of operator/operand
#define	MAXSTACK	100 // Maximum value stack depth
#define NUMBER		'0' // Signal detection of a number in input
#define MFUNC		'm' // Signal detection of a math.h function

int	getop(char []);
void	push(double);
double	pop(void);
double	apply_func(char [], double);

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

	printf("Reverse-Polish Notation Calculator:\n>");
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case MFUNC:
			push(apply_func(s, pop()));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			opd2 = pop();
			push(pop() - opd2);
			break;
		case '/':
			opd2 = pop();
			if (opd2 == 0.0)
				printf("Error: Zero division\n");
			else
				push(pop() / opd2);
			break;
		// 4.4: Add provisions for modulo operator
		case '%':
			opd2 = pop();
			if (opd2 == 0.0)
				printf("Error: Zero division\n");
			else
				push((int)pop() % (int)opd2);
			break;
		case '\n':
			printf("\t%.8g\n>", pop());
			break;
		default:
			printf("Error: Unknown operator/operand %s\n", s);
			break;
		}
	}

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

//4.5: Apply provisions for math.h functions
char func_sin[]		= "sin";
char func_cos[]		= "cos";
char func_tan[]		= "tan";
char func_asin[]	= "asin";
char func_acos[]	= "acos";
char func_atan[]	= "atan";
char func_sinh[]	= "sinh";
char func_cosh[]	= "cosh";
char func_tanh[]	= "tanh";
char func_exp[]		= "exp";
char func_log[]		= "log";
char func_log10[]	= "logten";
char func_sqrt[]	= "sqrt";

double apply_func(char s[], double f)
{
	double x;

	if (!strncmp(s, func_sin, strlen(func_sin)))
		x = sin(f);
	else if (!strncmp(s, func_cos, strlen(func_cos)))
		x = cos(f);
	else if (!strncmp(s, func_tan, strlen(func_tan)))
		x = tan(f);
	else if (!strncmp(s, func_asin, strlen(func_asin)))
		x = asin(f);
	else if (!strncmp(s, func_acos, strlen(func_acos)))
		x = acos(f);
	else if (!strncmp(s, func_atan, strlen(func_atan)))
		x = atan(f);
	else if (!strncmp(s, func_sinh, strlen(func_sinh)))
		x = sinh(f);
	else if (!strncmp(s, func_cosh, strlen(func_cosh)))
		x = cosh(f);
	else if (!strncmp(s, func_tanh, strlen(func_tanh)))
		x = tanh(f);
	else if (!strncmp(s, func_exp, strlen(func_exp)))
		x = exp(f);
	else if (!strncmp(s, func_log, strlen(func_log)))
		x = log(f);
	else if (!strncmp(s, func_log10, strlen(func_log10)))
		x = log10(f);
	else if (!strncmp(s, func_sqrt, strlen(func_sqrt)))
		x = sqrt(f);
	else {
		printf("Error: Unknown function %s\n", s);
		x = f;
	}

	return x;
}

#define UGBUFSIZE 8

char	ugbuf[UGBUFSIZE];
int	ugbufp = 0;

int	getch(void);
void	ungetch(int);

int getop(char s[])
{
	int i, c, cc, op;

	i = 0;
	while ((s[i] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	// Not a number or function
	if (!isdigit(c) && !isalpha(c) && c != '.' && c != '-')
		op = c;
	// 4.4: Add provisions for negative numbers
	else if (c == '-') {
		// if the lookahead is a digit, ensure the negative is recorded
		// and push the lookahead back
		if (isdigit(cc = getch())) {
			s[i] = c;
			c = cc;
			ungetch(cc);
		}
		else
			op = c;
	// 4.5: Add provisions for math.h functions
	} else if (isalpha(c)) {
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);

		op = MFUNC;
	}

	if(isdigit(c)) {
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

