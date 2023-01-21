#include "sort.h"

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

void bubble_sort(int *array, size_t size)
{
	size_t i, j = 0;
	int tmp;

	while (j < size && size >= 2)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
		}
		j++;
	}
}
