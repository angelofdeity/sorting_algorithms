#include "sort.h"

/**
 * maxim - Gets the maximum value of an array
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
	return (max);
}

/**
 * occurrence_set - Sets the number of occurrences by index
 * @array: Input array
 * @size: Size of array
 * @occurrence: Array to set
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
 * sum_occurrence - Sums up index array values with predecessor values
 * @occurrence: Array to sum
 * @max: Size of array
*/
void sum_occurrence(int *occurrence, int max)
{
	int i = 0, j = 1;

	while (i <= max && j <= max)
	{
		occurrence[j] = occurrence[j] + occurrence[i];
		i++;
		j++;
	}
}

/**
 * sort_count - Sorts an array of integer
 * @array: Array to sort
 * @size: size of array
 * @occurrence: Array of occurrences
 *
 * Return: A new array containing the sorted value of array
*/
int *sort_count(int *array, size_t size, int *occurrence)
{
	size_t i = 0;
	int *sort = malloc(sizeof(int) * size);

	if (sort == NULL)
		return (NULL);

	while (i < size)
	{
		sort[occurrence[array[i]] - 1] = array[i];
		occurrence[array[i]]--;
		i++;
	}
	return (sort);
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
	int *occurrence, *counting;
	size_t i = 0;

	if (size < 2)
		return;

	max = maxim(array, size);
	occurrence = malloc(sizeof(int) * (max + 1));
	if (occurrence == NULL)
		return;

	occurrence_set(array, size, occurrence);
	sum_occurrence(occurrence, max + 1);
	print_array(occurrence, max + 1);
	counting = sort_count(array, size, occurrence);
	if (counting == NULL)
	{
		free(occurrence);
		return;
	}
	while (i < size)
	{
		array[i] = counting[i];
		i++;
	}
	free(counting);
	free(occurrence);
}
