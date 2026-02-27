// Exercise 1-13a: Write a program to print a histogram of the lengths of words
// in its input. Horizontal graph

#include <stdio.h>

#define RANGE	32

int main()
{
	int c;
	int wl, mwlp;

	// wls[0] - Position of most frequent word count
	//		it is useful to not have to search for this
	// wls[1] - Count of words of length 1
	// wls[RANGE - 1] - counts of len >= RANGE
	long wls[RANGE];

	wl	= 0;
	mwlp	= 0;
	for (int i = 0; i < RANGE; ++i)
		wls[i] = 0;

	while ((c = getchar()) != EOF) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			++wl;
		} else {
			if (wl > 0) {
				++wls[wl];
				if (wls[wl] > wls[wls[0]])
					wls[0] = wl;
			}

			wl = 0;
		}
	}

	mwlp = wls[0];

	for (int i = 0; i < wls[mwlp]; ++i) {
		printf("%3d|", wls[mwlp] - i);

		for (int j = 1; j <= RANGE; ++j) {
			int pc;

			if (wls[j] >= wls[mwlp] - i)
				pc = '*';
			else
				pc = ' ';

			printf("%3c", pc);
		}

		printf("\n");
	}

	printf("%7d", 1);
	for (int i = 2; i < RANGE; ++i)
		printf("%3d", i);
	printf("+\n\n");

	for(int i = 0; i < RANGE; ++i)
		if (wls[i] > 0)
			printf("%3d -- %d\n", i, wls[i]);
	printf("\n");
}
