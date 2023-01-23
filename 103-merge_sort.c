#include "sort.h"

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using merge sort
 * @array: Array to sort
 * @size: Size of the array
*/
void merge_sort(int *array, size_t size)
{
	int i, left_size, right_size;
	int left[size / 2], right[size/ 2 + 1];

	if (size < 2)
		return;

	left_size = size / 2;
	right_size = size - left_size;

}
