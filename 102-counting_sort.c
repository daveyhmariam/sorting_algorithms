#include "sort.h"


/**
 * counting_sort - sorting using count sorting
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
*/
void counting_sort(int *array, size_t size)
{
	int sz = (int) size;
	int *freq, *sorted;
	int i, max;

	if (size < 2 || array == NULL)
		return;
	for (max = 0, i = 0; i < sz; i++)
		if (array[i] > max)
			max = array[i];
	max = max + 1;
	freq = (int *) malloc(sizeof(int) * (max));
	sorted = (int *) malloc(sizeof(int) * sz);
	if (freq == NULL || !sorted)
	{
		free(freq);
		free(sorted);
	}
	for (i = 0; i < max; i++)
		freq[i] = 0;
	for (i = 0; i < sz; i++)
		freq[array[i]]++;
	for (i = 1; i < max; i++)
		freq[i] += freq[i - 1];
	print_array(freq, max);
	for (i = sz - 1; i >= 0; i--)
	{
		freq[array[i]]--;
		sorted[freq[array[i]]] = array[i];
	}
	for (i = 0; i < sz; i++)
		array[i] = sorted[i];
	free(freq);
	free(sorted);
}
