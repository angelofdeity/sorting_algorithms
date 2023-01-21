#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using
 * shell sort algorithm (Knuth sequence)
 * @array: The array to sort
 * @size: The size of the array
*/
void shell_sort(int *array, size_t size)
{
	int gap = 1;
	size_t i;
	int j, temp;

	if (size < 2)
		return;

	while ((size_t)gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
