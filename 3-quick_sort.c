#include "sort.h"

void quick_sort(int *array, size_t size);
void sort_part(int *arr, size_t size, size_t i_low, size_t pivot);

/**
 * partition - sorts the partitions
 * @arr: array
 * @size: array size
 * @i_low: index low
 * @pivot: pivot
 *
 * Return: pivot
*/
size_t partition(int *arr, size_t size, size_t i_low, size_t pivot)
{
	size_t i, save_i = i_low;
	int temp = 0;

	for (i = i_low; i < pivot; i++)
	{
		if (arr[i] < arr[pivot])
		{
			if (i != save_i)
			{
				temp = arr[i];
				arr[i] = arr[save_i];
				arr[save_i] = temp;
				print_array(arr, size);
			}
			save_i++;
		}
	}
	if (arr[save_i] > arr[pivot])
	{
		temp = arr[save_i];
		arr[save_i] = arr[pivot];
		arr[pivot] = temp;
		print_array(arr, size);
	}
	return (save_i);
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
	size_t pivot = 0;

	if (i_low < i_hight)
	{
		pivot = partition(arr, size, i_low, i_hight);
		if (i_low < pivot)
		{
			sort_part(arr, size, i_low, pivot - 1);
		}
		if (pivot < size - 1)
		{
			sort_part(arr, size, pivot + 1, i_hight);
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
