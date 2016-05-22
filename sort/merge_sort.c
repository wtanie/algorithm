#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int p, int q, int r)
{
	// [p->q, q+1->r]
	int a_len = q - p + 1;
	int b_len = r - q;
	int *a_tmp;
	int *b_tmp;
	int *a_gard;
	int *b_gard;
	int *start;
	int *result;
	a_tmp = (int *)malloc(sizeof(int) * a_len);
	b_tmp = (int *)malloc(sizeof(int) * b_len);

	int i, j;
	for (i = 0, j = p - 1; i < a_len; i++, j++) {
		*(a_tmp + i) = *(arr + j);
	}
	for (i = 0, j = q; i < b_len; i++, j++) {
		*(b_tmp + i) = *(arr + j);
	}
	a_gard = a_tmp + a_len;
	b_gard = b_tmp + b_len;
	result = (int *)malloc(sizeof(int) * (a_len + b_len));
	start = result;
	for (; a_tmp < a_gard && b_tmp < b_gard;) {
		if (*a_tmp < *b_tmp) {
			*result = *a_tmp;
			a_tmp++;
		} else {
			*result = *b_tmp;
			b_tmp++;
		}
		result++;
	}
	if (a_tmp == a_gard) {
		while (b_tmp < b_gard) {
			*result = *b_tmp;
			b_tmp++;
			result++;
		}
	}
	if (b_tmp == b_gard) {
		while (a_tmp < a_gard) {
			*result = *a_tmp;
			a_tmp++;
			result++;
		}
	}
	for (i = p - 1; i < r; i++, start++) {
		*(arr + i) = *start;
	}
}

void merge_sort(int *arr, int p, int r)
{
	int q;
	if (p < r) {
		q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}