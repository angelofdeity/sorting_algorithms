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
	int array[] = {13, 12, 4, 9, 20, 18, 5, 7, 17, 6, 16, 2, 14, 3, 15};

	/* 	int array[] = {8, 7, 6, 1, 0, 9, 2};
	 */
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	quick_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
