#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP		100 // Maximum width of operator/operand
#define	MAXSTACK	100 // Maximum value stack depth
#define MAXSYMBOL	26  // Maximum amount of variable names, including
			    // special variable '^' for most recently printed
			    // value
#define NUMBER		'0' // Signal detection of a number in input
#define MFUNC		'm' // Signal detection of a math.h function
#define SYMBOL		'v' // Signal detection of a variable; only single
			    // letter variables are supported

int	getop(char []);
void	push(double);
double	pop(void);
// 4.4: Add additional stack functions
double	peek(void);	// View top of stack without popping
double	dup(void);	// Duplicate top of stack
double	swaptop(void);	// Swap top of stack with element beneath it
void	clear(void);	// Clear all stack elements
void	print(int);	// Print stack elements
// 4.5: Add support for math.h functions
double	apply_func(char [], double);

// 4.6: Add functions to define and lookup variables
int	declared(char []);
void	declare(char []);
void	assign(char [], double);
double	lookup(char []);

// Value stack and stack pointer
double	val[MAXSTACK];
int	valsp = 0;

// 4.6: Simple symbol table to allow definition of single-char variable names
// plus a lookup to determine if a given symbol name is declared
double	symbol_table[MAXSYMBOL];
double	symbol_lookup[MAXSYMBOL] = { 0 };

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
		case SYMBOL:
			if (declared(s)) {
				push(lookup(s));
			} else {
				declare(s);
				assign(s, peek());
			}
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
		case '^':
			opd2 = pop();
			push(pow(pop(), opd2));
			break;
		// 4.4: Add provisions for modulo operator
		case '%':
			opd2 = pop();
			if (opd2 == 0.0)
				printf("Error: Zero division\n");
			else
				push((int)pop() % (int)opd2);
			break;
		case '?':
			print(valsp);
			break;
		case '@':
			clear();
			break;
		case '\n':
			printf("\t%.8g\n>", peek());
			break;
		default:
			printf("Error: Unknown operator/operand %s\n", s);
			clear();
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

// 4.4: Add support for additional stack operations

double peek(void)
{
	double f;

	if (valsp > 0)
		f = val[valsp - 1];
	else
		f = val[valsp];

	return f;
}

double dup(void)
{
	push(peek());
	return peek();
}

double swaptop(void)
{
	double top, next;

	if (valsp >= 2) {
		top = pop();
		next = pop();
		push(top);
		push(next);
	} else if (valsp == 1) {
		top = pop();
		next = 0.0;
		push(top);
		push(next);
	} else {
		next = 0.0;
	}

	return next;
}

void print(int n) {
	int v;

	v = valsp;
	if (n > valsp)
		n = valsp;

	while (v - 1 >= 0 && v - 1 >= valsp - n) {
		printf(" %.8g ,", val[v - 1]);
		--v;
	}
	printf("\n");
	return;
}

void clear(void) {
	while (valsp != 0)
		pop();

	return;
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

// 4.6: Add functions to support variable definitions
int declared(char s[])
{
	char sym;

	sym = s[0];
	return symbol_lookup[sym - 'a'];
}

void declare(char s[])
{
	char sym;

	sym = s[0];
	symbol_lookup[sym - 'a'] = 1;
	return;
}

void assign(char s[], double f)
{
	char sym;

	if (!declared(s))
		declare(s);

	sym = s[0];
	symbol_table[sym - 'a'] = f;

	return;
}

double lookup(char s[])
{
	double	f;
	char	sym;

	sym = s[0];
	f = symbol_table[sym - 'a'];

	return f;
}

int	getch(void);
void	ungetch(int);
// 4.7: Add a routine ungets that pushes an entire string back
int	ungets(char []);

int getop(char s[])
{
	int i, c, cc, op;

	i = 0;
	while ((s[i] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	// Not a number or function
	if (!isdigit(c) && !islower(c) && c != '.' && c != '-')
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
	// 4.6: Add provisions for single-letter variable name declations
	} else if (islower(c)) {
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);

		if (strlen(s) > 1)
			op = MFUNC;
		else
			op = SYMBOL;
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

int	pushback = '\0';

// Retrieve pushed-back character if one exists otherwise read from stdin
int getch(void)
{
	int c;

	if (pushback != '\0') {
		c = pushback;
		pushback = '\0';
	} else {
		c = getchar();
	}

	return c;
}

// Push excess character back to be read again
void ungetch(int c)
{
	if (pushback != '\0') {
		printf("Error: Pusback limit exceeded for %d - %d waiting\n",
		       c, pushback);
	} else {
		pushback = c;
	}

	return;
}

// 4.7: Pushback an entire string, or as much of it as possible
// int ungets(char s[])
// {
// 	int pb;
//
// 	for (pb = 0; pb < UGBUFSIZE && s[pb] != '\0'; ++pb)
// 		ungetch(s[pb]);
//
// 	return pb;
// }
