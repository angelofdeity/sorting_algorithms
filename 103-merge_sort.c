#include "sort.h"

/**
 * merge - Sorts an array of integers, by merging
 * the left half and the right half
 * @array: Input array
 * @left_half: Left half of the array
 * @right_half: Right half of the array
 * @size: Size of the array
 */

void split(int *array, size_t size, int *new)
{
	size_t i, middle = size / 2;

	if (size < 2)
		return;

	printf("Merging...\n");
	for (i = 0; i < middle; i++)
		new[i] = array[i];
	printf("[left]:");
	print_array(new, middle);

	for (i = middle; i < size; i++)
		new[i] = array[i];
	printf("[right]:");
	print_array(new + middle, size - middle);
	printf("[Done]\n");

	split(new, middle, new);
	split(new, size - middle, new);
}

void merge(int *array, int *new, size_t size)
{
	int i, j, middle = size / 2, k;

	for (i = 0, j = middle, k = 0; i < middle && j < size; i++, j++)
	{
		if (new[i] < new[j])
			array[k] = 
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

	if (size < 2)
		return;

	new = malloc(sizeof(int) * size);

	split(array, size, new);

	/*merge(array, left_half, right_half, size);*/
	free(new);
}
