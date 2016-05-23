/*
 * 测试归并排序数组合并子过程
 */

#include <stdio.h>
#include <stdlib.h>

void simple_merge(int *arr_m, int m, int *arr_n, int n);

int main()
{
	int arr_m[5] = {1, 3, 5, 7, 9};
	int arr_n[5] = {2, 4, 6, 8, 10};
	simple_merge(arr_m, 5, arr_n, 5);
	return 0;
}

/* 简单的有序数组合并函数，函数内部构建合并后数组，并打印合并后的值 */
void simple_merge(int *arr_m, int m, int *arr_n, int n)
{
	int *result;
	int i;
	int j;
	int k;

	result = malloc(sizeof(int) * (m + n));
	for (i = 0, j = 0; i < m && j < n;) {
		if (*(arr_m + i) < *(arr_n + j)) {
			*(result + i + j) = *(arr_m + i);
			i++;
		} else {
			*(result + i + j) = *(arr_n + j);
			j++;
		}
	}
	while (j == n && i < m) {
		*(result + i + j) = *(arr_m + i);
		i++;
	}
	while (i == m && j < n) {
		*(result + i + j) = *(arr_n + j);
		j++;
	}
	k = 0;
	while (k < m + n) {
		printf("result[%d]: %d\n", k, *(result + k));
		k++;
	}
}
