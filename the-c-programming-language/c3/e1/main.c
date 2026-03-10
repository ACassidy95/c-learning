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
	int	i, x, lx, idxn, idxo;
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

		idxo = binsearch_orig(x, nums, SEARCH_SIZE);
		idxn = binsearch(x, nums, SEARCH_SIZE);

		printf("Orig binsearch: %d\nNew binsearch: %d\n\n", idxo, idxn);
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
	int low, high, mid, val;

	val = -1;
	low = 0;
	high = n - 1;

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
	}

	return val;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	mid = -1;
	low = 0;
	high = n - 1;

	while (mid != x) {
		mid = (low + high) / 2;

		if (x <= v[mid]) {
			high = mid + 1;
		} else {
			low = mid + 1;
		}
	}

	return mid;
}

