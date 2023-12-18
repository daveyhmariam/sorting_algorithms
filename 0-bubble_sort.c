#include "sort.h"

/**
 * bubble_sort - sorting using bubble sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, swap, p;

	swap = 0;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j] ^= array[j + 1];
				array[j + 1] ^= array[j];
				array[j] ^= array[j + 1];
				swap = 1;
			}
			if (swap == 1)
				for (p = 0; p < size; p++)
				{
					print_array(array, size);
					swap = 0;
				}
		}
	}
}