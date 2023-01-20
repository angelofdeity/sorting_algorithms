#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending
* order using the Bubble sort algorithm
* @array: Pointer to the array to be sorted
* @size: Size of the array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp, swapped;

	if (size < 2)
		return;

	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
			print_array(array, size);
			j++;
		}
		if (!swapped)
			break;
		i++;
	}
}
