#include "sort.h"

/**
 * unique_items - Isolates the unique items in an array
 * @array: Input array
 * @size: Size of array
 * 
 * Return: A new array containing the uniq elements of the array
*/
arr_t *unique_items(int *array, size_t size)
{
    int i, c, j, uniq_size = 0, uniq;
    int *uniq_it = malloc(sizeof(int) * size);
    arr_t *unique;

    if (uniq_it == NULL)
		return NULL;

	unique = malloc(sizeof(arr_t));
	if (unique == NULL)
	{
		free(uniq_it);
		return (NULL);
	}

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
            uniq_it[uniq_size] = c;
            uniq_size++;
        }
    }

	unique->array = uniq_it;
	unique->size = uniq_size;

    return (unique);
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
	arr_t *unique_elem;

	if (size < 2)
		return;

	unique_elem = unique_items(array, size);
	uniq_size = unique_elem->size;
	counting = unique_elem->array;
	printf("uniq: %d\n", uniq_size);
	printf("arr size: %lu\n", size);
	print_array(counting, uniq_size);
}
