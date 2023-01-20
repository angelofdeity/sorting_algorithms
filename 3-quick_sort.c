#include "sort.h"

/**
 * swap - swaps 2 integers
 * @a - pointer to first integer
 * @b - pointer to second integer
 */

void swap(int *a, int *b)
{
	int tmp = *b;

	*b = *a;
	*a = tmp;
}
/**
 * quick_sort - sorts an array
 * @array- array to sort
 * @size - size of array
 */
void quick_sort(int *array, size_t size)
{
	int pivot;
	size_t i, j;

	pivot = array[size - 1];
	/* sorter(array, size); */
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (array[j] <= pivot)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
				break;
			}
		}
	}
}
