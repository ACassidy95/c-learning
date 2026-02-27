// Exercise 1-13a: Write a program to print a histogram of the lengths of words
// in its input. Horizontal case

#include <stdio.h>

#define	STATE_IN	1
#define STATE_OUT	0

#define RANGE	32 // i.e. word lengths 1-31, and 32+

int main()
{
	int c, state;
	int wl;

	// wls[0] - counts of len 1
	// wls[RANGE - 1] - counts of len 32+
	int wls[RANGE];

	wl = 0;
	state = STATE_OUT;

	for (int i = 0; i < RANGE; ++i)
		wls[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = STATE_OUT;
			if (wl > 0) {
				// Offset by 1, i.e wls[0]
				// holds count for len 1, etc.
				++wls[wl - 1];
				wl = 0;
			}
		} else {
			wl++;
		}
	}

	for (int i = 0; i < RANGE; ++i)
		printf("%3d", wls[i]);
	printf("\n");
	for (int i = 0; i < RANGE; ++i)
		printf("%3d", i + 1);
	printf("\n");
}
