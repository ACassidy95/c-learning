// Exercise 3-1: Provided binary search implementation makes two tests inside
// the loop when one would suffice. Write a version with only one test inside
// the loop.

#include <stdio.h>

#define MAX_BUF		32
#define SEARCH_SIZE	1048576 // 2^20

int get_num(char s[], int maxlen);
int atoi(char s[]);
int binsearch_orig(int x, int v[], int n);
int binsearch(int x, int v[], int n);

int main()
{
	int	i, x, lx, news, origs;
	int	nums[SEARCH_SIZE];
	char	sx[MAX_BUF];

	for (i = 0; i < SEARCH_SIZE; ++i)
		nums[i] = i;

	printf("Enter search value: ");
	while ((lx = get_num(sx, MAX_BUF)) > 0) {
		x = atoi(sx);

		if (x > SEARCH_SIZE) {
			printf("Too large, x = %d\n", SEARCH_SIZE);
			x = SEARCH_SIZE - 1;
		}

		origs = binsearch_orig(x, nums, SEARCH_SIZE);
		news = binsearch(x, nums, SEARCH_SIZE);

		printf("Orig binsearch num steps: %d\n", origs);
		printf("New binsearch num steps: %d\n\n", news);
		printf("Enter search value: ");
	}

	return 0;
}

int get_num(char s[], int maxlen)
{
	int c, i;

	for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	s[i] = '\0';
	return i;
}

int atoi(char s[])
{
	int n, i;

	n = 0;
	for (i = 0; s[i] != '\0'; ++i)
		n = n * 10 + (s[i] - '0');

	return n;
}

int binsearch_orig(int x, int v[], int n)
{
	int low, high, mid, val, steps;

	val = -1;
	low = 0;
	high = n - 1;
	steps = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		if (x < v[mid]) {
			high = mid + 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {
			val = mid;
			low = high + 1;
		}
		++steps;
	}

	return steps;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid, steps;

	mid = -1;
	low = 0;
	high = n - 1;
	steps = 0;

	while (mid != x) {
		mid = (low + high) / 2;

		if (x <= v[mid]) {
			high = mid + 1;
		} else {
			low = mid + 1;
		}

		++steps;
	}

	return steps;
}

