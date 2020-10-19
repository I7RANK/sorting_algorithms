#include "sort.h"
#include <unistd.h>

/**
 * selection_sort - sorts a list using the selection sort algorithm
 * @array: pointer to the array
 * @size: the size of the array
 *
 * Return: na
*/
void selection_sort(int *array, size_t size)
{
	unsigned long i = 0, j = 0;
	unsigned long index = 0;
	int num_i = 0, change = 0;

	if (!array || size < 2)
		return;

	for (i = 0; array[i]; i++)
	{
		num_i = array[i];
		for (j = i + 1; array[j]; j++)
		{
			if (num_i > array[j])
			{
				num_i = array[j];
				index = j;
				change = 1;
			}
		}
		if (change)
		{
			num_i = array[i];
			array[i] = array[index];
			array[index] = num_i;
			print_array(array, size);
		}
		change = 0;
	}
}
