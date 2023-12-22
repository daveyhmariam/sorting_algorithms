#include "sort.h"


void shell_sort(int *array, size_t size)
{
	size_t i, j, knuth, tmp;

	if (!array || size < 2)
		return;

	knuth = 1;
	while (knuth <= size / 2)
		knuth = knuth * 3 + 1;
	for (i = 0; i < size && knuth >= 1; i++)
		{
			for (j = 0; (j + knuth) < size; j++)
			{
				if (array[j] < array[knuth])
				{
					tmp = array[j];
					array[j] = array[knuth];
					array[knuth] = tmp;
					print_array(array, size);
				}
			}
			knuth /= 3;
		}
	for (i = 0; i < size; i++)
	{
		for (j = i; j > 0; j--)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
			}
		}
	}
}
