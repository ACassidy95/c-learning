// Exercise 3-4: In a two's complement number representation, the provided
// version of itoa does not handle the largest negative number
// -2^(wordsize - 1). Explain why and modify it to print the value correctly,
// regardless of the underlying machine.

#include <stdio.h>

#define MAXBUF 64

int get_num(char s[], int maxbuf);
void reverse(char s[]);
int atoi(char s[]);
void itoa_orig(int n, char s[]);
void itoa_new(int n, char s[]);

int main()
{
	return 0;
}
