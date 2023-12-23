#include "sort.h"


void shell_sort(int *array, size_t size)
{
	size_t  i, j, kn = 0;
	int tmp;
	if (!array || size < 2)
		return;

	while (kn <= size / 3)
		kn = kn * 3 + 1;
	
	for (; kn >= 1; kn /= 3)
	{
	for (i = kn; i < size; i++)
	{
		for (j = i; j >= kn && array[j] < array[j - kn]; j -= kn)
		{
			tmp = array[j];
			array[j] = array[j - kn];
			array[j - kn] = tmp;
			print_array(array, size);
		}
	}
	}
}
