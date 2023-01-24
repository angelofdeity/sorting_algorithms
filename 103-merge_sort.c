#include "sort.h"

/**
 * merge - Sorts an array of integers, by merging
 * the left half and the right half
 * @array: Input array
 * @left_half: Left half of the array
 * @right_half: Right half of the array
 * @size: Size of the array
 */

void split(int *array, size_t start, size_t size, int *new)
{
	size_t i, middle;

	if (size - start < 2)
		return;

	middle = start + (size - start) / 2;

	for (i = start; i <= middle; i++)
		new[i] = array[i];

	for (i = middle; i < size; i++)
		new[i] = array[i];

	split(array, start, middle, new);
	split(array, middle, size, new);
	merge(array, new, start, middle, size);
}

void merge(int *array, int *new, size_t start, size_t middle, size_t size)
{
	size_t i, j, k;

	for (i = start, j = middle, k = 0; i < middle && j < size; k++)
	{
		if (new[i] < new[j])
		{
			array[k] = new[i];
			i++;
		}	
		else
		{
			array[k] = new[j];
			j++;
		}
	}

	while (i < middle)
	{
		array[k] = new[i];
		i++;
		k++;
	}

	while (j < size)
	{
		array[k] = new[j];
		j++;
		k++;
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using merge sort
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *new;
	size_t start = 0;

	if (size < 2)
		return;

	new = malloc(sizeof(int) * size);

	split(array, start, size, new);
	/*merge(array, left_half, right_half, size);*/
	free(new);
}
