#include "sort.h"
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i = left, j = mid, k = left;
	while (i < mid && j <= right)
	{
		if (array[i] < array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i < mid)
		temp[k++] = array[i++];
	while (j <= right)
		temp[k++] = array[j++];

	for (int i = left; i <= right; i++)
		array[i] = temp[i];
}

void merge_sort_with_print(int *array, int *temp, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left + 1) / 2;
		merge_sort_with_print(array, temp, left, mid - 1);
		merge_sort_with_print(array, temp, mid, right);
		printf("Merging...\n[left]: ");
		for (int i = left; i < mid; i++)
			printf("%d ", array[i]);
		printf("\n[right]: ");
		for (int i = mid; i <= right; i++)
			printf("%d ", array[i]);
		merge(array, temp, left, mid, right);
		printf("\n[Done]: ");
		for (int i = left; i <= right; i++)
			printf("%d ", array[i]);
		printf("\n");
	}
}

void merge_sort(int *array, size_t size)
{
	int *temp = malloc(size * sizeof(int));
	merge_sort_with_print(array, temp, 0, size - 1);
	free(temp);
}
