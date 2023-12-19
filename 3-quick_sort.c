#include "sort.h"

/**
 * quick_sort - sorting with quick sorting algorithm
 * @array: array to be sorted
 * @size: size of partition
 * Return: Nothing
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	lumito(array, 0, size - 1, size);
}

/**
 * lumito - lumito partition scheme
 * @array: array to be sorted
 * @low: lower bound
 * @high: upper bound
 * @size: size of array
 * Return: Nothing
*/
void lumito(int *array, int low, int high, int size)
{
	int pivot, i, j;

	if (low >= high)
		return;
	pivot = high;
	j = low;

	for (i = low; i < high; i++)
	{
		if (array[i] <= array[pivot] && j != i)
		{
			swap_quick(&array[i], &array[j]);
			j++;
			print_array(array, size);
		}
		if (array[i] <= array[pivot] && j == i)
		{
			j++;
		}
	}
	if (j != i)
	{
		swap_quick(&array[j], &array[pivot]);
		print_array(array, size);
	}
	lumito(array, low, j - 1, size);
	lumito(array, j + 1, high, size);
}


/**
 * swap_quick - swaps two elements content
 *
 * @a: the first element
 * @b: the second element
 *
 * Return: nothing
*/

void swap_quick(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
