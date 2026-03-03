// Exercise 1-13a: Write a program to print a histogram of the lengths of words
// in its input. Horizontal graph

#include <stdio.h>

#define FREQ_RANGE	32
#define DISP_RANGE	24

int main()
{
	int	c;
	int	wl, maxpos, minpos;
	float	y, ymin, ymax, ystep;

	// wls[0] - Position of most frequent word count
	//		it is useful to not have to search for this
	// wls[1] - Count of words of length 1
	// wls[FREQ_RANGE - 1] - counts of len >= FREQ_RANGE
	long wls[FREQ_RANGE];

	wl	= 0;
	maxpos	= 0;
	minpos	= 1;
	for (int i = 0; i < FREQ_RANGE; ++i)
		wls[i] = 0;

	while ((c = getchar()) != EOF) {
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			++wl;
		} else {
			if (wl > 0) {
				++wls[wl];
				if (wls[wl] > wls[maxpos]) {
					wls[0] = wl;
					maxpos = wl;
				}
			}

			wl = 0;
		}
	}

	maxpos = wls[0];
	for (int i = 1; i < FREQ_RANGE; ++i)
		if (wls[i] < wls[minpos] && wls[i] > 0)
			minpos = i;

	ymin	= wls[minpos];
	ymax	= wls[maxpos];

	int dr = DISP_RANGE;
	if (ymax < DISP_RANGE)
		dr = ymax;
	ystep	= (ymax - ymin) / dr;

	for (int i = 0; i <= dr; ++i) {
		y = ymax - (i * ystep);
		printf("%6.0f|", y);

		for (int j = 1; j < FREQ_RANGE; ++j) {
			int pc;
			if (wls[j] >= wls[minpos]) {
				if (wls[j] == wls[maxpos] - (i * ystep))
					pc = '.';
				else if (wls[j] >= wls[maxpos] - (i * ystep))
					pc = '*';
				else
					pc = ' ';

				printf("%3c", pc);
			} else {
				++j;
			}
		}

		printf("\n");
	}

	printf("%10c", '_');
	for (int i = 2; i< FREQ_RANGE; ++i)
		if (wls[i] >= wls[minpos])
			printf("%3c", '_');
	printf("\n%10d", 1);
	for (int i = 2; i < FREQ_RANGE; ++i)
		if (wls[i] >= wls[minpos])
			printf("%3d", i);

	printf("\n\nMax: %5d Min: %5d Mode: %5d Display Range: %5d Y-Step: %5f\n"
	       ,wls[maxpos], wls[minpos], maxpos, dr, ystep);
}
