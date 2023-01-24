#include "sort.h"

/**
 * merge - Sorts an array of size_tegers, by merging
 * the left half and the right half
 * @array: Input array
 * @temp: temporary array buffer
 * @left: start index of the array
 * @mid: middle index of the array
 * @right: end index of the array
 */

void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

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
 * merge_sort_with_print - Sorts an array of size_tegers,
 * by merging the left half and the right half
 * @array: Input array
 * @temp: temporary array buffer
 * @left: start index of the array
 * @right: end index of the array
 */

void merge_sort_with_print(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (right - left >= 1)
	{
		mid = left + (right - left + 1) / 2;
		merge_sort_with_print(array, temp, left, mid - 1);
		merge_sort_with_print(array, temp, mid, right);
		printf("Merging...\n[left]: ");
		print_array(array + left, mid - left);
		printf("[right]: ");
		print_array(array + mid, right - mid + 1);
		merge(array, temp, left, mid, right);
		printf("[Done]: ");
		print_array(array + left, right - left + 1);
	}
}

/**
 * merge_sort - driver merge sort function
 * @array: array to be sorted
 * @size: size of array
 * Description: implements the top-down merge sort algorithm
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;
	merge_sort_with_print(array, temp, 0, size - 1);
	free(temp);
}
