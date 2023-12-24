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
	int i, idx, max;

	if (size < 2)
		return;
	for (max = 0, i = 0; i < sz; i++)
		if (array[i] > max)
			max = array[i];
	max = max + 1;
	freq = (int *) malloc(sizeof(int) * (max));
	sorted = (int *) malloc(sizeof(int) * sz);
	if (freq == NULL || !sorted)
		return;
	for (i = 0; i < max; i++)
		freq[i] = 0;
	for (i = 0; i < sz; i++)
		freq[array[i]] += 1;
	for (i = 1; i < max; i++)
		freq[i] += freq[i - 1];
	for (i = 0; i < max; i++)
	{
		if (i != 0)
			printf(", ");
		printf("%d", freq[i]);
	}
	for (i = 0; i < sz; i++)
	{
		idx = freq[array[i]];
		sorted[idx - 1] = array[i];
		freq[array[i]] -= 1;
	}
	for (i = 0; i < sz; i++)
		array[i] = sorted[i];
	free(freq);
	free(sorted);
}
