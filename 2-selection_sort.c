#include "sort.h"

/**
 * selection_sort - sorting with selection sorting
 * @array: array to be sorted
 * @size: size of array
 * Return: nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t out, in, small;
	int tmp;

	for (out = 0; out < size; out++)
	{
		small = out;
		tmp = array[small];
		for (in = out + 1; in < size; in++)
		{
			if (array[in] < array[small])
				small = in;
		}
		if (small != out)
		{
			array[out] = array[small];
			array[small] = tmp;
			print_array(array, size);
		}
	}
}
