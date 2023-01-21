#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int temp, min_index;

	if (size < 2)
		return;

	while (i < size - 1)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_index])
				min_index = j;
			j++;
		}
		temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
		print_array(array, size);
		i++;
	}
}

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j;
	int *small, tmp;

	while (i < size - 1 && size >= 2)
	{
		small = &array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *small)
			{
				small = &array[j];
			}
		}
		tmp = *small;
		*small = array[i];
		array[i] = tmp;
		print_array(array, size);
		i++;
	}
}
