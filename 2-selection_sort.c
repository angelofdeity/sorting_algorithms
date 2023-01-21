#include "sort.h"

/**
 * selection_sort - Sorts an array of integers
 * using the selection sort algorithm
 * @array: The array to sort
 * @size: Size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int *small, tmp;

	while (i < size - 1 && size >= 2)
	{
		small = &array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < *small)
			{
				small = &array[j];
			}
		}
		if (array[i] > *small)
		{
			tmp = *small;
			*small = array[i];
			array[i] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
