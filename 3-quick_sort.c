#include "sort.h"

void quick_sort(int *array, size_t size);
void sort_part(int *arr, size_t size, size_t i_low, size_t pivot);

/**
 * partition - sorts the partitions
 * @arr: array
 * @size: array size
 * @i_low: index low
 * @i_hight: index hight
 *
 * Return: pivot
*/
size_t partition(int *arr, size_t size, size_t i_low, size_t i_hight)
{
	int temp = 0;
	size_t save_i = 0, i, j, sort = 1;

	for (i = i_low; i <= i_hight; i++)
	{
		if (arr[i] > arr[i_hight])
		{
			save_i = i;
			for (j = i + 1; j < i_hight; j++)
			{
				if (arr[j] < arr[i_hight])
				{
					temp = arr[j];
					arr[j] = arr[save_i];
					arr[save_i] = temp;
					print_array(arr, size);
					save_i++;
				}
			}
			temp = arr[i_hight];
			arr[i_hight] = arr[save_i];
			arr[save_i] = temp;
			print_array(arr, size);
			return (save_i);
		}
	}
	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] <= arr[i + 1])
			sort++;
	}
	if (sort == size)
		return (0);
	sort_part(arr, size, i_low, i_hight - 1);
	return (0);
}

/**
 * sort_part - sorts a number list in recursive mode
 * @arr: the array with number to sort
 * @size: the size of the array
 * @i_low: index low
 * @i_hight: index hight
 *
 * Return: na
*/
void sort_part(int *arr, size_t size, size_t i_low, size_t i_hight)
{
	size_t pivot = 0, sort = 1, i;

	for (i = 0; i < size - 1; i++)
	{
		if (arr[i] <= arr[i + 1])
			sort++;
	}
	if (sort == size)
		return;

	if (i_low < i_hight)
	{
		pivot = partition(arr, size, i_low, i_hight);
		if (i_low < pivot)
		{
			sort_part(arr, size, i_low, pivot - 1);
		}
		else
		{
			sort_part(arr, size, pivot + 1, i_hight);
			for (i = 0; i < size - 1; i++)
			{
				if (arr[i] <= arr[i + 1])
					sort++;
			}
			if (sort == size)
				return;
			sort_part(arr, size, 0, size - 1);
		}
	}
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
