#include <stdio.h>

void insert_sort_asc(int *array, int n);
void insert_sort_desc(int *array, int n);

int main()
{
	int i;
	int array[8] = { 3, 5, 6, 4, 1, 4, 5, 6 };
	printf("insert_sort_asc:\n");
	insert_sort_asc(array, 8);
	for (i = 0; i < 8; i++) {
		printf("array[%d]: %d\n", i, *(array + i));
	}
	printf("insert_sort_desc:\n");
	insert_sort_desc(array, 8);
	for (i = 0; i < 8; i++) {
		printf("array[%d]: %d\n", i, *(array + i));
	}
	getchar();
	return 0;
}

void insert_sort_asc(int *array, int n)
{
	int i, j;
	int min;
	for (i = 1; i < n; i++) {
		min = *(array + i);
		j = i - 1;
		while (j >= 0 && *(array + j) > min) {
			*(array + j + 1) = *(array + j);
			j = j - 1;
		}
		*(array + j + 1) = min;
	}
}

void insert_sort_desc(int *array, int n)
{
	int i, j;
	int max;
	for (i = 1; i < n; i++) {
		max = *(array + i);
		j = i - 1;
		while (j >= 0 && *(array + j) < max) {
			*(array + j + 1) = *(array + j);
			j = j - 1;
		}
		*(array + j + 1) = max;
	}
}