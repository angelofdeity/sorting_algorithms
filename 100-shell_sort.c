#include "sort.h"

/**
 * shell_sort - Sorts an array of integers using
 * shell sort algorithm (Knuth sequence)
 * @array: The array to sort
 * @size: The size of the array
*/
void shell_sort(int *array, size_t size)
{
	int gap = size / 2;
	int i, j, temp;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
		}
		gap /= 2;
	}
}
