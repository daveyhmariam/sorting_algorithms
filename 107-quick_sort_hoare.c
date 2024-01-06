#include "sort.h"

/**
 * quick_sort_hoare - sorting with hoare partition method
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 1)
		return;
	hoare(array, 0, (int)size - 1, size);
}

/**
 * hoare - recursive function to perform hoare partitioning
 * @array: array to be sorted
 * @start: lower index
 * @end: higher index
 * @size: size of array
 * Return: Nothing
 */

void hoare(int *array, int start, int end, size_t size)
{
	int i, j, pivot, tmp;

	if (end <= start)
		return;
	pivot = array[end];
	i = start;
	j = end;
	while (i < j)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		printf("before i: %d  j: %d\n", i, j);
		if (i < j)
		{
			tmp = array[i];
			array[i++] = array[j];
			array[j--] = tmp;
			print_array(array, size);
		}
		printf("After i: %d  j: %d\n", i, j);
	}
	hoare(array, start, i - 1, size);
	hoare(array, i, end, size);
}
