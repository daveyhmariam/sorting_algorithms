#include "sort.h"

/**
 * bitonic_sort - sorting using bitonic sorting algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing
 */

void bitonic_sort(int *array, size_t size)
{
	int flag, *sorting;

	if (!array || size < 2)
		return;
	flag = 1;
	sorting = (int *) malloc(sizeof(int) * size);
	if (!sorting)
		return;
	bitonic_split(array, 0, (int)size, flag, sorting, (int) size);
	free(sorting);
}

/**
 * bitonic_split - recursive function to split the array
 * @array: array to be sorted
 * @start: starting index
 * @end: ending index
 * @flag: directional flag for ascending descending
 * @sorting: auxiliary array
 * @size: size of array
 * Return: Nothing
 */
void bitonic_split(int *array, int start, int end,
					int flag, int *sorting, int size)
{
	int center;

	center = (end - start) / 2;
	if (start >= end || (end - start) % 2 != 0)
		return;
	if (flag == 1)
		printf("Merging [%d/%d] (UP):\n", (end - start), size);
	if (flag == 0)
		printf("Merging [%d/%d] (DOWN):\n", (end - start), size);
	print_array3(array, start, end);
	bitonic_split(array, start, (start + center), 1, sorting, size);
	bitonic_split(array, (start + center), end, 0, sorting, size);
	if (flag == 1)
		up(array, start, end, sorting, size);
	if (flag == 0)
		down(array, start, end, sorting, size);
}

/**
 * print_array3 - print entire array
 * @array: array
 * @start: start of array
 * @end: end of array
 * Return: Nothing
 */

void print_array3(int *array, int start, int end)
{
	int i;

	i = start;
	while (i < end)
	{
		if (i != start)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * up - merge sort increasing bitonic order based on flag
 * @array: array to besorted
 * @start: starting index
 * @end: ending index
 * @sorting: auxiliary array
 * @size: size of array
 * Return: Nothing
 */

void up(int *array, int start, int end, int *sorting, int size)
{
	int i, j, center, count;

	center = (end - start) / 2;
	/*increasing monotonic*/
	for (count = start; count < end; count++)
		for (i = start, j = end - 1; i < (start + center) || j >= (start + center);)
		{
			if (array[i] > array[j])
			{
				sorting[count++] = array[j--];
				if (j < (start + center))
					while (i < (start + center))
						sorting[count++] = array[i++];
			}
			if (array[i] <= array[j])
			{
				sorting[count++] = array[i++];
				if (i >= (start + center))
					while (j >= (start + center))
						sorting[count++] = array[j--];
			}
		}
	for (i = 0; i < end; i++)
		array[i] = sorting[i];
	printf("Result [%d/%d] (UP):\n", (end - start), size);
	print_array3(array, start, end);

}

/**
 * down - merge sort decreasing bitonic order based on flag
 * @array: array to besorted
 * @start: starting index
 * @end: ending index
 * @sorting: auxiliary array
 * @size: size of array
 * Return: Nothing
 */

void down(int *array, int start, int end, int *sorting, int size)
{
	int i, j, center, count;

	center = (end - start) / 2;
	/*decreasing monotonic*/

	for (count = start; count < end; count++)
		for (i = (start + center - 1), j = (start + center); i >= start || j < end;)
		{
			if (array[i] < array[j])
			{
				sorting[count++] = array[j++];
				if (j == (end))
					while (i >= start)
					{
						sorting[count++] = array[i--];
					}
			}
			if (array[i] >= array[j])
			{
				sorting[count++] = array[i--];
				if (i < start)
					while (j < end)
						sorting[count++] = array[j++];
			}
		}
	for (i = 0; i < end; i++)
		array[i] = sorting[i];
	printf("Result [%d/%d] (DOWN):\n", (end - start), size);
	print_array3(array, start, end);
}
