#include <stdio.h>

int binsearchBetter(int, int [], int);
int binsearch(int, int [], int);

int
main()
{
	int tab[] = {1, 1, 1, 2, 3, 4, 4, 4, 5, 5, 8, 8, 8, 9, 29, 67, 345, 753467};
	printf("%d\t%d\n", binsearch(345, tab, 18), binsearchBetter(345, tab, 18));
	return 0;
}

/* With two ifs in while loop */
int
binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		printf("SHIT: mid --> %d\tlow --> %d\thigh --> %d\n", mid, low, high);
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int
binsearchBetter(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	while (low <= high) {

		mid = (low + high) / 2;

		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		printf("mid --> %d\tlow --> %d\thigh --> %d\n", mid, low, high);
	}
	if (v[high] == x)
			return high;
	else
		return -1;
}
