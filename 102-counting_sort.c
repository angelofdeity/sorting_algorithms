#include "sort.h"

/**
 * unique_size - Gets the number of unique items in an array;
 * @array: Input array
 * @size: Size of array
 * 
 * Return: The number of unique elements of the array
*/
int unique_size(int *array, size_t size)
{
    int i, c, j, uniq, unique_size = 0;
    int uniq_it[size];

    for (i = 0; i < size; i++)
    {
        c = array[i];
        j = 0;
        uniq = 1;
        while (uniq_it[j])
        {
            if (c == uniq_it[j])
            {
                uniq = 0;
                break;
            }
            j++;
        }
        if (uniq)
        {
            uniq_it[unique_size] = c;
            unique_size++;
        }
    }
    return (unique_size);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the counting sort algorithm
 * @array: The array to sort
 * @size: The size of the array
*/
void counting_sort(int *array, size_t size)
{
    int i, c, j, u = 0, counter, uniq, min = array[0], max = 0;
    int *counting;
    int uniq_size;

	if (size < 2)
		return;
    uniq_size = unique_size(array, size);

	counting = malloc(sizeof(int) * uniq_size);
	if (counting == NULL)
		return;

	printf("uniq: %d\n", uniq_size);
}
