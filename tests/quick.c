#include <stdio.h>
#include <stddef.h>
#include "sort.h"
void sort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void swap(int *l_int, int *r_int);
/**
 * quick_sort - sort an array using the quick sort algorithm.
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	if (array == NULL)
		return;
	sort(array, 0, size - 1, size);
}
/**
 * sort - recursively sorts an array using quick sort.
 * @array: array to sort
 * @low: lower index range
 * @high: higher index range
 */
void sort(int *array, int low, int high, size_t size)
{
	int pivot_idx;
	if (low < high)
	{
		/* divide and get index of division */
		pivot_idx = partition(array, low, high, size);
		/* conquer from left, then right */
		sort(array, low, pivot_idx - 1, size);
		sort(array, pivot_idx + 1, high, size);
	}
}
/**
 * partition - divides an array into two. First half should be lower than the
 * pivot point. The pivot should be the last item in the array. i.e. array[high]
 * @array: array to divide.
 * @low: lower index to start with.
 * @high: higher index to stop at.
 *
 * Return: The pivot point in the array.
 */
int partition(int *array, int low, int high, size_t size)
{
	/*int pivot_idx = 0;  this should point to the pivot point. */
	int i, j = low;
	int pivot;

	pivot = array[high];
	/* loop from low to 1 index from high */
	for (i = j + 1; i < high; i++)
	{
		if (array[i] <= pivot)
		{ /* it is in the wrong half, swap it and increase pivot index */
			swap(&array[j], &array[i]);
			print_array(array, size);
			j++;
		}
	}
	/* swap the number in the pivot point with the pivot number */
	if (array[j] > pivot)
	{
		swap(&array[j], &array[high]);
		print_array(array, size);
	}
	return (j);
}
/**
 * swap - swaps to integers
 * @l_int: left integer
 * @r_int: right integer
 */
void swap(int *l_int, int *r_int)
{
	int temp;

	temp = *l_int;
	*l_int = *r_int;
	*r_int = temp;
}
