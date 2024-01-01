#include "sort.h"

/**
 * heap_sort - sorting with heap-sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: Nothing 
 */

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, i, size, size);
	for (i = size - 1; i > 0; i--)
	{
		array[0] += array[i];
		array[i] = array[0] - array[i];
		array[0] -= array[i];
		print_array(array, size);
		heapify(array, 0, i, size);
	}
}

/**
 * heapify - make a max heap
 * @array: array to be sorted
 * @parent: parent node
 * Return: Nothing
 */

void heapify(int *array, int parent, int base, size_t size)
{
	int chldl, chldr, tmp, max;

	chldl = (parent * 2) + 1;
	chldr = (parent * 2) + 2;
	max = parent;
	if (chldl < base)
		max = array[parent] > array[chldl] ? parent: chldl;
	if (chldr < base)
		max = array[max] > array[chldr] ? max: chldr;
	if (max != parent)
	{
		tmp = array[max];
		array[max] = array[parent];
		array[parent] = tmp;
		print_array(array, size);
		heapify(array, max, base, size);
	}
}

int main()
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};

	heap_sort(array, 10);
	return (0);
}
