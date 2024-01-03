#ifndef SORT_H
#define SORT_H
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap(listint_t *swap);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void lumito(int *array, int low, int high, int size);
void swap_quick(int *a, int *b);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void split(int *array, size_t start, size_t end, int *sorting);
void merge(int *array, size_t start, size_t end, int *sorting);
void print_array2(int *array, size_t start, size_t end);
void heap_sort(int *array, size_t size);
void heapify(int *array, int base, int parent, size_t size);
void radix_sort(int *array, size_t size);
void count_array_sort(int *array, int *sort, int rad, size_t size);
int max(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_split(int *array, int start, int end, int flag, int *sorting);
void print_array3(int *array, int start, int end);
void up(int *array, int start, int end, int *sorting);
void down(int *array, int start, int end, int *sorting);
#endif
