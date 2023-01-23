#include "sort.h"

/**
 * merge - Sorts an array of integers, by merging
 * the left half and the right half
 * @array: Input array
 * @left_half: Left half of the array
 * @right_half: Right half of the array
 * @size: Size of the array
*/
void merge(int *array, int *left_half, int *right_half, size_t size)
{

}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using merge sort
 * @array: Array to sort
 * @size: Size of the array
*/
void merge_sort(int *array, size_t size)
{
	size_t middle = size / 2, i, j;
	int left_half[middle], right_half[size - middle];

	if (size < 2)
		return;

	printf("Merging...\n");
	for (i = 0; i < middle; i++)
		left_half[i] = array[i];
	printf("[left]:");
	print_array(left_half, middle);

	for (j = 0, i = middle; i < size; i++, j++)
		right_half[j] = array[i];
	printf("[right]:");
	print_array(right_half, size - middle);
	printf("[Done]\n");

	merge_sort(left_half, (size_t)middle);
	merge_sort(right_half, size - middle);

	merge(array, left_half, right_half, size);
}
