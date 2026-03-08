// Exercise 2-3: Write a function htoi(s) which converts a string of hexadecimal
// digits (including an optional 0x or 0X prefix) into its equivalent integer
// value. The allowable digits are 0-9, a-f, and A-F

#include <ctype.h>
#include <stdio.h>

#define MAX_HEX_DIGITS	128

int get_hex_number(char buffer[], int maxdigits);
long convert_hex_number(char buffer[]);

int main()
{
	long len, dec;
	char buffer[MAX_HEX_DIGITS];

	while ((len = get_hex_number(buffer, MAX_HEX_DIGITS)) > 0) {
		dec = convert_hex_number(buffer);
		printf("Decimal value: %5lu\n", dec);
	}

	return 0;
}

int get_hex_number(char buffer[], int maxdigits)
{
	int i, c;
	int err;

	err = 0;
	for (i = 0; i < maxdigits - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		buffer[i] = c;

	buffer[i] = '\0';
	return i;
}

long convert_hex_number(char buffer[])
{
	int c, i, pre, offset;
	long dec;

	i = 0;
	pre = i + 1;

	if (buffer[i] == '0' && (buffer[pre] == 'x' || buffer[pre] == 'X')) {
		offset = 2;
	} else {
		offset = 0;
	}

	dec = 0;
	for (i = i + offset; isxdigit(buffer[i]); ++i) {
		c = buffer[i];
		if (isdigit(c))
			dec = dec * 16 + (c - '0');
		else if (islower(c)) {
			dec = dec * 16 + (10 + c - 'a');
		} else if (isupper(c)) {
			dec = dec * 16 + (10 + c - 'A');
		}
	}

	return dec;
}
