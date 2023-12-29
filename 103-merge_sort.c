#include "sort.h"

/**
 * merge_sort - soring with merge sort algorithms
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
*/
void merge_sort(int *array, size_t size)
{
	int *sorting;

	if (array == NULL || size < 2)
		return;
	sorting = (int *) malloc(sizeof(int) * size);
	if (!sorting)
	{
		free(sorting);
		return;
	}
	split(array, 0, size - 1, sorting);
	free(sorting);
}

/**
 * split - split array to sub arrays
 * @array: array to be splited
 * @sorting: auxiliary array to make the sort
 * @start: starting index of array to be splited
 * @end: ending index of array to be splited
 * Return: Nothing
*/
void split(int *array, size_t start, size_t end, int *sorting)
{
	int left, right;

	if (start >= end)
		return;

	if ((end - start) % 2 == 0)
		left = (int) (((end - start) / 2) + start) - 1;
	else if ((end - start) % 2 != 0)
		left = (int) (((end - start) / 2) + start);
	right = left + 1;
	split(array, start, left, sorting);
	split(array, right, end, sorting);
	merge(array, start, end, sorting);
}

/**
 * merge - merge split arrays in asending order
 * @array: array to be splited
 * @sorting: auxiliary array to make the sort
 * @start: starting index of array to be merged
 * @end: ending index of array to be merged
 * Return: Nothing
*/
void merge(int *array, size_t start, size_t end, int *sorting)
{
	int pass, i, j;
	int left, right;

	if ((end - start) % 2 == 0)
		left = (int) (((end - start) / 2) + start) - 1;
	else if ((end - start) % 2 != 0)
		left = (int) (((end - start) / 2) + start);
	right = left + 1;
	printf("Merging...\n");
	printf("[left]: ");
	print_array2(array, start, left);
	printf("[right]: ");
	print_array2(array, right, end);
	for (pass = start; pass <= (int) end;)
	{
		for (i = start, j = right; i <= (int) left || j <= (int) end;)
		{
			if (array[i] > array[j])
			{
				sorting[pass++] = array[j++];
				if (j > (int) end)
					while (i <= (int)left)
						sorting[pass++] = array[i++];
			}
			if (array[i] <= array[j])
			{
				sorting[pass++] = array[i++];
				if (i > (int)left)
					while (j <= (int) end)
						sorting[pass++] = array[j++];
			}
		}
	}
	for (i = start; i <= (int)end; i++)
		array[i] = sorting[i];
	printf("[Done]: ");
	print_array2(array, start, end);
}

/**
 * print_array2 - print array
 * @array: array to be prined
 * @start: starting index of array
 * @end: ending index of array
 * Return: Nothing
*/
void print_array2(int *array, size_t start, size_t end)
{
	int i;

	for (i = start; i <= (int)end; i++)
	{
		if (i != (int)start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
