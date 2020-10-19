#include "sort.h"

/**
 * sort_part - sorts a number list in recursive mode
 * @arr: the array with number to sort
 * @size: the size of the array
 * @i_low: the index where go to start te comparations
 * @pivot: the number of pivot
 *
 * Return: na
*/
void sort_part(int *arr, size_t size, size_t i_low, size_t pivot)
{
	size_t save_i = 0, i, j;
	int temp = 0;

	for (i = i_low; i <= pivot; i++)
	{
		if (arr[i] >= arr[pivot])
		{
			save_i = i;
			for (j = i + 1; j <= pivot; j++)
			{
				if (arr[j] < arr[pivot] || j == pivot)
				{
					temp = arr[save_i];
					arr[save_i] = arr[j];
					arr[j] = temp;
					/* if swap equals numbers no print */
					if (arr[j] != arr[save_i])
						print_array(arr, size);
					if (j == pivot)
					{
					/* no indent betty warnings */
					if (save_i == i_low)
						i_low++;
					else
						pivot--;
					if (pivot == 0)
						return;
					sort_part(arr, size, i_low, pivot);
					}
					save_i++;
				}
			}
		}
	}
	/* pivot must be equal to i_low for the array is sorted */
	if (pivot != i_low)
		sort_part(arr, size, i_low, pivot - 1);
}

/**
 * quick_sort - sorts a list using the quick sort algorithm
 * @array: pointer to array
 * @size: size of the array
 *
 * Return: na
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sort_part(array, size, 0, size - 1);
}
