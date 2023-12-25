#include "sort.h"

int largest(int *array, size_t size);

/**
 * counting_sort - sorts by counting elements occurence
 *
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: nothing
*/

void counting_sort(int *array, size_t size)
{
	int *count, i;
	int len = largest(array, size), *array2;

	if (!array || size == 1)
	return;

	count = malloc(sizeof(int) * len + 1);

	if (!count)
	{
		free(count);
		return;
	}

	for (i = 0; i <= len; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= len; i++)
		count[i] = count[i] + count[i - 1];

	print_array(count, len + 1);
	array2 = malloc(sizeof(int) * size);

	if (!array2)
	{
		free(array2);
		return;
	}

	for (i = size - 1; i >= 0; i--)
	{
		count[array[i]]--;
		array2[count[array[i]]] = array[i];
	}

	for (i = 0; i < (int)size; i++)
		array[i] = array2[i];

	free(count);
	free(array2);
}

/**
 * largest - find the largest element in the array
 *
 * @array: the array
 * @size: size of the array
 *
 * Return: largest number
*/

int largest(int *array, size_t size)
{
	int i = 0, len = 0;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > len)
		len = array[i];
	}
	return (len);
}