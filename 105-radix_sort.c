#include "sort.h"

/**
 * radix_sort - sorting by radix sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int rad, *sort, mx;

	if (!array)
		return;
	sort = (int *) malloc(sizeof(int) * size);
	if (!sort)
	{
		free(sort);
		return;
	}
	mx = max(array, size);
	for (rad = 1; (mx / rad) > 0; rad *= 10)
	{
		count_array_sort(array, sort, rad, size);
		print_array(array, size);
	}

}

/**
 * count_array_sort - count array elements auxiliary to count sort;
 * @array: array to be sorted
 * @sort: auxiliary array
 * @rad: current radix
 * @size: size of array
 * Return: the max element
 */
void count_array_sort(int *array, int *sort, int rad, size_t size)
{
	int i, idx;
	int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i < (int) size; i++)
	{
		idx = (array[i] / rad) % 10;
		count[idx]++;
	}
	for (i = 1; i < (int) size; i++)
		count[i] = count[i] + count[i - 1];
	for (i = (int) size - 1; i >= 0; i--)
	{
		idx = count[((array[i] / rad) % 10)] - 1;
		sort[idx] = array[i];
		count[((array[i] / rad) % 10)]--;
	}
	for (i = 0; i < (int) size; i++)
		array[i] = sort[i];
}


/**
 * max - return the max element
 * @array: array to be sorted
 * @size: size of array
 * Return: the max element
 */
int max(int *array, size_t size)
{
	int i, mx;

	mx = array[0];
	for (i = 1; i < (int) size; i++)
	{
		if (array[i] > mx)
			mx = array[i];
	}
	return (mx);
}
