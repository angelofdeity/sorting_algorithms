#include "sort.h"

/**
 * swap - swaps 2 integers
 * @a:  pointer to first integer
 * @b:  pointer to second integer
 */

void swap(int *a, int *b)
{
	int tmp = *b;

	*b = *a;
	*a = tmp;
}

/**
 * partition - partition the array using Lomuto partition scheme
 * @array: array to partition
 * @low: lower bound of the array
 * @high: upper bound of the array
 * @size: size of array
 * Return: pivot index
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	print_array(array, size);

	return (i);
}

/**
 * sort_help - recursive function that sorts the array
 *@array: array to sort
 * @low: lower bound of the array
 * @high: upper bound of the array
 * @size: size of array
 */

void sort_help(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size);

		sort_help(array, low, pivot_index - 1, size);
		sort_help(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array
 * @array: array to sort
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort_help(array, 0, size - 1, size);
}
