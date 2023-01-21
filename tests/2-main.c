#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {34, 46, 13, 43, 19, 18, 6, 49, 36, 31, 2, 16, 33, 30, 3, 41, 1, 42, 8, 9, 40, 21, 14, 23, 45};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	selection_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
