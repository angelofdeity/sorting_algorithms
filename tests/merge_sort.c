#include "sort.h"

/**
 * merge - Sorts an array of integers, by merging
 * the left half and the right half
 * @array: Input array
 * @left_half: Left half of the array
 * @right_half: Right half of the array
 * @size: Size of the array
 */
/**
void merge(int *array, int *left_half, int *right_half, size_t size)
{
	;
}
*/

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using merge sort
 * @array: Array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t middle = size / 2, i, j;
	int *new;

	new = malloc(sizeof(int) * size);

	if (size < 2)
	{
		free(new);
		return;
	}

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

	merge_sort(new, middle);
	merge_sort(new, size - middle);

	/*merge(array, left_half, right_half, size);*/
}
