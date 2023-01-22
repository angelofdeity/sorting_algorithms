#include "sort.h"

/**
 * max - Gets the maximum value of an array
 * @array: Input array
 * @size: Size of array
 * 
 * Return: The max value of array
*/
int maxim(int *array, size_t size)
{
	size_t i = 0;
	int max = 0;

	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return max;
}


/**
 * set_range - Sets array range from 0 to max
 * @max: Maximum range
 * 
 * Return: A node of range array from 0 to max
 * and occurrences initialized to 0
*/
/*
array_range_t *set_range(int max)
{
	array_range_t *range = malloc(sizeof(array_range_t));
	int i = 0;

	if (range == NULL)
		return NULL;

	range->range = malloc(sizeof(int) * max);
	if (range->range == NULL)
	{
		free(range);
		return (NULL);
	}
	range->occurrence = malloc(sizeof(int) * max);
	if (range->occurrence == NULL)
	{
		free(range->range);
		free(range);
		return (NULL);
	}

	while (i <= max)
	{
		range->range[i] = 1;
		range->occurrence[i] = 0;
		i++;
	}
	return (range);
}
*/

void occurrence_set(int *array, size_t size, int *occurrence)
{
	size_t i = 0, j;
	int count;

	while (i < size)
	{
		count = 0;
		j = 0;
		while (j < size)
		{
			if (array[j] == array[i])
				count++;
			j++;
		}
		occurrence[array[i]] += 1;
		i++;
	}
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the counting sort algorithm
 * @array: The array to sort
 * @size: The size of the array
*/
void counting_sort(int *array, size_t size)
{
    int max;
	int *occurrence;

	if (size < 2)
		return;
	
	max = maxim(array, size);
	occurrence = malloc(sizeof(int) * (max + 1));
	if (occurrence == NULL)
		return;

	occurrence_set(array, size, occurrence);
	printf("Max %d\n", max);
	print_array(occurrence, max + 1);
}
