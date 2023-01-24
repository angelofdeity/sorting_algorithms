#include "sort.h"

/**
 * merge - Sorts an array of integers, by merging
 * the left half and the right half
 * @array: Input array
 * @temp: temporary array buffer
 * @left: start index of the array
 * @mid: middle index of the array
 * @right: end index of the array
 */

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

	for (i = left; i <= right; i++)
		array[i] = temp[i];
}

/**
 * merge_sort_with_print - Sorts an array of integers,
 * by merging the left half and the right half
 * @array: Input array
 * @temp: temporary array buffer
 * @left: start index of the array
 * @right: end index of the array
 */

void merge_sort_with_print(int *array, int *temp, int left, int right)
{
	int mid, i;

	if (left < right)
	{
		mid = left + (right - left + 1) / 2;
		merge_sort_with_print(array, temp, left, mid - 1);
		merge_sort_with_print(array, temp, mid, right);
		printf("Merging...\n[left]: ");
		for (i = left; i < mid; i++)
			printf("%d ", array[i]);
		printf("\n[right]: ");
		for (i = mid; i <= right; i++)
			printf("%d ", array[i]);
		merge(array, temp, left, mid, right);
		printf("\n[Done]: ");
		for (i = left; i <= right; i++)
			printf("%d ", array[i]);
		printf("\n");
	}
}

/**
 * merge_sort - driver merge sort function
 * @array: array to be sorted
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *temp = malloc(size * sizeof(int));

	merge_sort_with_print(array, temp, 0, size - 1);
	free(temp);
}
