#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * struct array_range_s - Counting node
 * @range: An array containing the range of input
 * @occurrence: Number of range occurrence
 */
typedef struct array_range_s
{
	int *range;
	int *occurrence;
} array_range_t;

void insertion_sort_list(listint_t **list);
void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int sorter(int *array, size_t size);
void print_list(const listint_t *list);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
int maxim(int *array, size_t size);
int *sort_count(int *array, size_t size, int *occurrence);
void sum_occurrence(int *occurrence, int max);
void occurrence_set(int *array, size_t size, int *occurrence);
void merge_sort(int *array, size_t size);
void merge(int *array, int *temp, size_t left, size_t mid, size_t right);
void merge_sort_with_print(int *array, int *temp, size_t left, size_t right);

#endif
