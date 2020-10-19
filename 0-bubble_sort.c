#include "sort.h"

/**
 * bubble_sort - sorts an array of integersin ascending order
 * @array: is the array to sort
 * @size: the size of the @array
 *
 * Return: na
*/
void bubble_sort(int *array, size_t size)
{
	unsigned long size_sort, i;
	int sort = 0;
	int tmp = 0;

	if (!array || size < 2)
		return;

	size_sort = size - 1;
	while (sort == 0)
	{
		for (i = 0; i <= size_sort; i++)
		{
			if (!array[i + 1])
				break;

			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
			}
			else if (i + 1 == size_sort)
				size_sort--;
		}
		if (size_sort == 0)
			sort = 1;
	}
}
