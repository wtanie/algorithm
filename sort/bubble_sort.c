#include <stdio.h>

void bubble_sort_asc(int *array, int n)
{
	int i, j;
	int tmp;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (*(array + j) < *(array + i)) {
				tmp = *(array + j);
				*(array + j) = *(array + i);
				*(array + i) = tmp;
			}
		}
	}
}

void bubble_sort_desc(int *array, int n)
{
	int i, j;
	int tmp;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++) {
			if (*(array + j) > *(array + i)) {
				tmp = *(array + j);
				*(array + j) = *(array + i);
				*(array + i) = tmp;
			}
		}
	}
}