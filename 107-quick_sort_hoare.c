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
 * @j: higher index
 * @size: size of array
 * Return: Nothing
 */

void hoare(int *array, int start, int end, size_t size)
{
	int i, j, pivot, tmp;

	if (end <= start)
		return;
	pivot = end;
	i = start;
	j = end;
	while (i < j)
	{
		while (array[i] <= array[pivot] && i < end)
			i++;
		while (array[j] > array[pivot] && j > start)
			j++;
		if (i < j)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
		if (i > j)
		{
			tmp = array[i];
			array[i] = array[pivot];
			array[pivot] = tmp;
			print_array(array, size);
		}
	}
	hoare(array, start, i - 1, size);
	hoare(array, i + 1, end, size);
}
