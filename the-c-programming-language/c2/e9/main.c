// Exercise 2-9: In a two's complement number system x &= (x-1) deletes the
// rightmost 1-bit in x. Explain why, use this observation to write a faster
// version of bitcount

#include <stdio.h>

#define MAXBUF 32

int get_num(char s[], int max);
int atoi(char s[]);
int bitcount_oc(unsigned x);
int bitcount_tc(unsigned x);

int main()
{
	unsigned int	lx, x;
	int		bco, bct;
	char		sx[MAXBUF];

	printf("Enter X value: ");
	while ((lx = get_num(sx, MAXBUF)) > 0) {
		x = atoi(sx);
		bco = bitcount_oc(x);
		bct = bitcount_tc(x);

		printf("OC Bitcount value: %5d\n", bco);
		printf("TC Bitcount value: %5d\n", bct);

		printf("Enter X value: ");
	}

	return 0;
}

int get_num(char s[], int max)
{
	int i, c;

	for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	// No need to preserve newline in a number
	s[i] = '\0';
	return i;
}

int atoi(char s[])
{
	int i, n;

	n = 0;
	for (i = 0; s[i] != '\0'; ++i)
		n = n * 10 + (s[i] - '0');

	return n;
}

// One's Complement version of bitcount. Slower than Two's Complement since it
// requires clearing all bits in x up to the MSB regardless of if they are set
// or not. 
int bitcount_oc(unsigned x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 0x1)
			++b;

	return b;
}

// Two's Complement version of bitconut. Faster than One's Complement since it
// automatically clears only the rightmost set bit as the lowest n bits of x-1
// are inverse of the lowest n bits of x.
int bitcount_tc(unsigned x)
{
	int b;

	for (b = 0; x != 0; x &= (x - 1))
		++b;

	return b;
}
